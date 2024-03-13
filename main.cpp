#include <array>
#include <cstdint>
#include <iostream>
#include <set>

int main() {
	size_t n, result;
	std::set <int16_t> cut_tiles;

	std::cin >> n;
	result = n * 4;
	for (size_t i = 0; i != n; i++) {
		int16_t x, y;
		std::cin >> x >> y;
		cut_tiles.emplace((x << 6) + y);
	}

	for (auto it : cut_tiles) {
		int16_t x = it >> 6, y = it ^ (x << 6), reduction = 0;
		std::array <int16_t, 4> check_tiles = {
			(x << 6) + (y + 1),
			((x - 1) << 6) + y,
			(x << 6) + (y - 1),
			((x + 1) << 6) + y
		};

		for (auto jt : check_tiles) {
			if (cut_tiles.contains(jt))
				reduction++;
		}

		result -= reduction;
	}

	std::cout << result;

	return 0;
}