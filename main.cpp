#include <cstdint>
#include <iostream>
#include <string>

int main() {
	bool has_lower = false, has_upper = false, has_number = false;
	std::string input;

	std::cin >> input;

	if (input.size() < 8) {
		std::cout << "NO";
		return 0;
	}

	for (auto it : input) {
		if (it >= 'a' && it <= 'z')
			has_lower = true;
		else if (it >= 'A' && it <= 'Z')
			has_upper = true;
		else if (it >= '0' && it <= '9')
			has_number = true;
	}

	std::cout << (has_lower && has_upper && has_number ? "YES" : "NO");

	return 0;
}