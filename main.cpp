#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <tuple>

std::tuple <bool, double> calc(double l, double x1, double v1, double x2, double v2) {
	if (x1 == x2 || l - x1 == x2 || l - x2 == x1)
		return { true, 0.f };
	if (v1 == 0 && v2 == 0)
		return { false, 0.f };

	double ax1 = std::abs(x1),
		av1 = std::abs(v1),
		ax2 = std::abs(x2),
		av2 = std::abs(v2),
		dx = std::abs(x1 - x2),
		dv = std::abs(v1 - v2);

	if (v1 == v2) {
		double x = (x1 + x2) / 2, dv = v1;
		if (x < l / 2 && dv < 0)
			dx = x;
		else if (x > l / 2 && dv < 0)
			dx = l / 2 + x;
		else if (x < l / 2 && dv > 0)
			dx = l / 2 - x;
		else if (x > l / 2 && dv > 0)
			dx = l - x;
		return { true, std::abs(dx / dv) };
	} else if (av1 == av2 && (v1 > 0 && v2 < 0 || v1 < 0 && v2 > 0))
		return { true, (ax1 + ax2) / (av1 + av2) };

	if (v1 * v2 > 0) {
		if (dx < l)
			return { true, dx / dv };
		else
			return { true, (dx + l) / dv };
	} else if (v1 * v2 < 0) {
		if (dx < l)
			return { true, dx / dv };
		else
			return { true, std::abs(dx - l) / dv };
	} else if (v1 == 0 && v2 > 0) {
		if (x1 < x2) 
			dx = l - dx;
		return { true, dx / dv };
	} else if (v1 > 0 && v2 == 0) {
		if (x1 > x2)
			dx = l - dx;
		return { true, dx / dv };
	}
}

int main() {
	int64_t length, x1, v1, x2, v2;

	std::cin >> length >> x1 >> v1 >> x2 >> v2;
	std::cout << std::fixed << std::setprecision(10);

	auto [result, time] = calc(length, x1, v1, x2, v2);

	if (result)
		std::cout << "YES\n" << time;
	else
		std::cout << "NO";
}