#include <iostream>
#include <cstdint>
#include <vector>

void print_vector(const std::vector <char>& signs) {
	for (const auto& it : signs)
		std::cout << it;
}

int main() {
	//0 is even, 1 is odd
	bool state, is_all_odd = true;
	size_t size = 0;
	std::vector <int> nums;
	std::vector <char> signs;

	std::cin >> size;
	nums.resize(size);
	signs.resize(size - 1, '+');
	std::cin >> nums[0];
	if (nums[0] < 0) 
		nums[0] = std::abs(nums[0]);
	state = nums[0] % 2;
	if (state == 0)
		is_all_odd = false;
	for (size_t i = 1; i != size; i++) {
		std::cin >> nums[i];
		if (nums[i] < 0) 
			nums[i] = std::abs(nums[i]);

		if (nums[i] % 2 == 0)
			is_all_odd = false;

		if ((state + nums[i] % 2) == 0 || (state + nums[i] % 2) == 2)
			state = 0;
		else if ((state + nums[i] % 2) == 1)
			state = 1;
	}
	if (state == 0) {
		if (is_all_odd)
			signs[0] = 'x';
		else for (size_t i = 0; i != size - 1; i++) {
			if ((nums[i] + nums[i + 1]) % 2 == 1) {
				signs[i] = 'x';
				break;
			}
		}
	}

	print_vector(signs);
}

//2 4 -5

//3 5 7 2

//5 450402558 -840167367 -231820501 586187125 -627664645

//3 390029247 153996608 -918017777

//4 -1 1 -1 1
