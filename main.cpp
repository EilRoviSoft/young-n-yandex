#include <iostream>
#include <cstdint>
#include <cmath>

struct interval_t {
	int64_t begin, end, length;
};

int main() {
	int64_t vt, vd, mt, md, total_trees;
	interval_t v, m, i;

	std::cin >> vt >> vd >> mt >> md;

	v.begin = vt - vd;
	v.end = vt + vd;
	v.length = v.end - v.begin + 1;
	m.begin = mt - md;
	m.end = mt + md;
	m.length = m.end - m.begin + 1;

	if (v.begin > m.end || m.begin > v.end) {
		i.length = 0;
	} else {
		i.begin = std::max(v.begin, m.begin);
		i.end = std::min(v.end, m.end);
		i.length = i.end - i.begin + 1;
	}

	total_trees = v.length + m.length - i.length;

	std::cout << total_trees;
}