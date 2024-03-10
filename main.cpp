#include <array>
#include <cstdint>
#include <iostream>
#include <set>
#include <string>
#include <vector>

enum Month {
	Dec = 11, Jan = 0, Feb,
	Mar, Apr, May,
	Jun, Jul, Aug,
	Sep, Oct, Nov
};

std::array <const std::string, 12> months_names = {
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
};

Month get_month_id(std::string month) {
	for (size_t i = 0; i != 12; i++)
		if (month == months_names[i]) {
			return (Month)i;
		}
}

enum Week {
	Mon = 0, Tue, Wed, Thu, Fri, Sat, Sun
};

std::array <const std::string, 7> days_of_a_week_names = {
	"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

Week get_day_of_a_week_id(std::string day_of_a_week) {
	for (size_t i = 0; i != 7; i++)
		if (day_of_a_week == days_of_a_week_names[i]) {
			return (Week)i;
		}
}

struct date_t {
	Month m;
	uint16_t d;
};

bool operator<(date_t lhs, date_t rhs) {
	if (lhs.m == rhs.m)
		return lhs.d < rhs.d;
	return lhs.m < rhs.m;
}

//std::array <size_t, 12> months_offset;

std::vector <date_t> alloc_days_of_a_year(size_t year) {
	bool is_leap_year = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	size_t filled = 0;
	std::array <size_t, 12> months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	std::vector <date_t> result;

	if (is_leap_year) {
		months[Feb]++;
		result.resize(366);
	} else result.resize(365);

	/*months_offset[0] = 0;
	for (size_t i = 1; i != 12; i++)
		months_offset[i] = months[i] + months_offset[i - 1];*/

	for (size_t month_id = 0; month_id != 12; month_id++) {
		for (size_t i = 0; i != months[month_id]; i++) {
			result[filled] = { (Month)month_id, (uint16_t)(i + 1) };
			filled++;
		}
	}

	return result;
}

int main() {
	size_t amount_of_holidays, current_year, min = 0, max = 0;
	Week starting_day;
	std::array <size_t, 7> days_of_a_week;
	std::set <date_t> holidays;
	std::vector <date_t> days_of_a_year;

	std::cin >> amount_of_holidays >> current_year;
	for (size_t i = 0; i != amount_of_holidays; i++) {
		std::string month;
		uint16_t day;
		std::cin >> day >> month;
		holidays.emplace(date_t{ get_month_id(month), day });
	}
	{
		std::string day_of_a_week;
		std::cin >> day_of_a_week;
		starting_day = get_day_of_a_week_id(day_of_a_week);
	}
	days_of_a_year = alloc_days_of_a_year(current_year);
	for (auto& it : days_of_a_week)
		it = 0;

	for (size_t i = 0; i != days_of_a_year.size(); i++) {
		if (!holidays.contains(days_of_a_year[i]))
			days_of_a_week[(i + starting_day) % 7]++;
	}

	min = max = 0;
	for (size_t i = 1; i != 7; i++) {
		if (days_of_a_week[min] > days_of_a_week[i])
			min = i;
		if (days_of_a_week[max] < days_of_a_week[i])
			max = i;
	}

	std::cout << days_of_a_week_names[max] << ' ' << days_of_a_week_names[min];
}