#include <cmath>
#include <iostream>

int main() {
	bool flag = false;
	int64_t n, k, d, place_number;
	std::cin >> n >> k >> d;

	for (place_number = 0; place_number != 10; place_number++)
		if ((n * 10 + place_number) % k == 0) {
			n = n * 10 + place_number;
			flag = true;
			break;
		}

	if (!flag) {
		n = -1;
		d = 1;
	}

	std::cout << n;
	for (size_t i = 0; i < d - 1; i++)
		std::cout << '0';
}