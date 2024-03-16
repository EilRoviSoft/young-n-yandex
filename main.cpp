#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <string>
#include <tuple>
#include <vector>

#define SIZET_MAX std::numeric_limits <size_t>::max()



struct data_t {
	size_t offset;
	std::shared_ptr <int64_t> result;
};

size_t binary_search(const std::vector <std::string>& where, std::string what) {
	size_t lhs = 0, rhs = where.size() - 1, idx, start_count = what.size();
	while (where[lhs] <= where[rhs]) {
		idx = std::floor((double)(lhs + rhs) / 2);
		if (where[idx].substr(0, start_count) < what)
			lhs = idx + 1;
		else if (where[idx].substr(0, start_count) > what)
			rhs = idx - 1;
		else
			return idx;
	}
	return SIZET_MAX;
}

bool equals(std::string lhs, std::string rhs) {
	return lhs.substr(0, rhs.size()) == rhs;
}

int main() {
	size_t words_size, requests_size, result_size = 0, idx;
	std::vector <std::string> words;
	std::vector <std::shared_ptr <int64_t>> result;
	std::map <std::string, std::vector <data_t>> requests;

	std::cin >> words_size >> requests_size;
	words.resize(words_size);
	for (auto& it : words)
		std::cin >> it;
	result.resize(requests_size);
	for (size_t i = 0; i != requests_size; i++) {
		size_t offset;
		std::string content;
		std::cin >> offset >> content;
		auto it = requests.find(content);
		if (it == requests.end())
			requests.insert({ content, std::vector <data_t>() });

		auto& temp = requests[content];
		auto temp_result = std::make_shared <int64_t>(-1);
		temp.push_back({ offset, temp_result });
		result[i] = temp_result;
		result_size++;
	}
	result.resize(result_size);

	for (auto [content, data] : requests) {
		int64_t i;
		idx = binary_search(words, content);
		for (i = idx - 1; i >= 0 && equals(words[i], content); i--);

		for (auto it : data) {
			if (i + it.offset < words.size() && equals(words[i + it.offset], content))
				*it.result = i + it.offset + 1;
		}
	}

	for (auto it : result)
		std::cout << *it << '\n';
}