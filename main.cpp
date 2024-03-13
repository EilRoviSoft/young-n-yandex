#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>

struct vector2 {
	int x, y;
};

int main() {
	constexpr int min_int = std::numeric_limits <int>::min();
	constexpr int max_int = std::numeric_limits <int>::max();

	vector2 min = { max_int, max_int }, max = { min_int, min_int }, cur;
	size_t k;

	std::cin >> k;
	for (size_t i = 0; i != k; i++) {
		std::cin >> cur.x >> cur.y;
		if (cur.x < min.x)
			min.x = cur.x;
		if (cur.x > max.x)
			max.x = cur.x;
		if (cur.y < min.y)
			min.y = cur.y;
		if (cur.y > max.y)
			max.y = cur.y;
	}

	std::cout << min.x << ' ' << min.y << ' ' << max.x << ' ' << max.y;

	return 0;
}