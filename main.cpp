#include <iostream>
#include <vector>
#include <list>

template <class _T>
class matrix {
public:
	const _T blank = 0;

	_T& at(size_t idx, size_t idy) {
		return this->m_content.at(idx + idy * this->m_width);
	}

	_T try_at(size_t idx, size_t idy) const {
		if (idx >= 0 && idx < this->m_width && idy >= 0 && idy < this->m_height)
			return this->m_content.at(idx + idy * this->m_width);
		return this->blank;
	}

	void resize(size_t width, size_t height, _T val = _T()) {
		this->m_width = width;
		this->m_height = height;
		this->m_content.resize(this->m_width * this->m_height, val);
	}

	size_t width() const { return this->m_width; }
	size_t height() const { return this->m_height; }
	size_t capacity() const { return this->m_content.size(); }

private:
	size_t m_width = 0, m_height = 0;
	std::vector <_T> m_content;
};

void mark_rook_area(size_t x, size_t y, const matrix <char>& input, matrix <int>& output) {
	output.at(x, y) = 1;
	bool u = true, l = true, r = true, d = true;
	for (size_t i = 1; u || l || r || d; i++) {
		if (u) {
			if (input.try_at(x, y - i) == '*')
				output.at(x, y - i) = 1;
			else
				u = false;
		}
		if (l) {
			if (input.try_at(x - i, y) == '*')
				output.at(x - i, y) = 1;
			else
				l = false;
		}
		if (r) {
			if (input.try_at(x + i, y) == '*')
				output.at(x + i, y) = 1;
			else
				r = false;
		}
		if (d) {
			if (input.try_at(x, y + i) == '*')
				output.at(x, y + i) = 1;
			else
				d = false;
		}
	}
}
void mark_bishop_area(size_t x, size_t y, const matrix <char>& input, matrix <int>& output) {
	output.at(x, y) = 1;
	bool ul = true, ur = true, dr = true, dl = true;
	for (size_t i = 1; ul || ur || dr || dl; i++) {
		if (ul) {
			if (input.try_at(x - i, y - i) == '*')
				output.at(x - i, y - i) = 1;
			else
				ul = false;
		}
		if (ur) {
			if (input.try_at(x + i, y - i) == '*')
				output.at(x + i, y - i) = 1;
			else
				ur = false;
		}
		if (dr) {
			if (input.try_at(x + i, y + i) == '*')
				output.at(x + i, y + i) = 1;
			else
				dr = false;
		}
		if (dl) {
			if (input.try_at(x - i, y + i) == '*')
				output.at(x - i, y + i) = 1;
			else
				dl = false;
		}
	}
}

struct figure_t {
	size_t x, y;
	char type;
};

int main() {
	matrix <char> input;
	matrix <int> mask;
	std::list <figure_t> figures;
	size_t result = 0;
	char temp;

	input.resize(8, 8, ' ');
	mask.resize(8, 8, 0);

	for (size_t i = 0; i != 64; i++) {
		std::cin >> temp;
		input.at(i % 8, i / 8) = temp;

		if (temp == 'B' || temp == 'R')
			figures.push_back({ i % 8, i / 8, temp });
	}

	for (const auto& it : figures) {
		switch (it.type) {
		case 'R':
			mark_rook_area(it.x, it.y, input, mask);
			break;

		case 'B':
			mark_bishop_area(it.x, it.y, input, mask);
			break;
		}
	}

	/*for (size_t i = 0; i != mask.width(); i++) {
		for (size_t j = 0; j != mask.height(); j++)
			std::cout << mask.at(j, i);
		std::cout << '\n';
	}*/

	for (size_t i = 0; i != 64; i++)
		result += mask.at(i % 8, i / 8);
	std::cout << (64 - result);
}