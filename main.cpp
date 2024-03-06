#include <iostream>
#include <cstdint>

int main() {
	//sil - spaces_in_line
	int64_t total = 0, n, sil;

	std::cin >> n;

	for (uint64_t i = 0; i != n; i++) {
		std::cin >> sil;
		total += sil / 4;
		sil %= 4;

		if (sil == 3)
			total += 2;
		else if (sil <= 2)
			total += sil;
	}

	std::cout << total;
}

//5 1 4 12 9 0
//8