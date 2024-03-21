#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>
#include <climits>

struct section_t {
	int64_t x1, x2;
	bool flag = true;
};

int main() {
	int64_t size, result = 0;
	std::vector <section_t> data;
	std::map <int64_t, std::vector <size_t>> positions;

	std::cin >> size;
	data.resize(size);
	for (size_t i = 0; i != data.size(); i++) {
		auto& temp = data[i];
		std::cin >> temp.x1 >> temp.x2;
	}

	for (size_t i = 0; i != data.size(); i++) {
		if (data[i].x1 == data[i].x2)
			continue;

		for (size_t j = 0; j != data.size(); j++) {
			if (i == j) continue;

			auto& a1 = data[i].x1;
			auto& a2 = data[i].x2;
			auto& a3 = data[j].x1;
			auto& a4 = data[j].x2;
			if ((data[i].flag || data[j].flag) && (a1 == a3 || a2 == a4 || (a1 < a3 && a2 > a4) || (a1 > a3 && a2 < a4))) {
				data[i].flag = false;
				data[j].flag = false;
			}
		}
	}

	for (const auto& it : data)
		result += it.flag;

	std::cout << result;

	return 0;
}