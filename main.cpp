#include <iostream>
#include <cstdint>
#include <vector>

int main() {
	size_t n, k, max_offset, sliding_window_lim;
	int cur_diff, max_diff = 0;
	std::vector <int> costs;

	std::cin >> n >> k;
	costs.resize(n);
	for (size_t i = 0; i != n; i++)
		std::cin >> costs[i];

	for (size_t i = 0; i != n - 1; i++) {
		max_offset = 0;
		sliding_window_lim = n - i > k ? k : n - i - 1;
		for (size_t j = 1; j <= sliding_window_lim; j++) {
			if (costs[i + j] > costs[i + max_offset])
				max_offset = j;
		}
		cur_diff = costs[i + max_offset] - costs[i];
		if (cur_diff > max_diff)
			max_diff = cur_diff;
	}

	std::cout << max_diff;

	return 0;
}