#include <iostream>
#include <cstdint>

namespace util {
	template <class _T>
	_T scan(std::istream& is = std::cin) {
		_T temp;
		is >> temp;
		return temp;
	}
}

struct scores_t {
	int f, s, t;
};

int main() {
	//bool is_ft_winner = false;
	scores_t team1, team2;
	int match_type, answer = 0;

	team1.f = util::scan <int>();
	std::cin.ignore(1);
	team2.f = util::scan <int>();
	team1.s = util::scan <int>();
	std::cin.ignore(1);
	team2.s = util::scan <int>();
	match_type = util::scan <int>();

	team1.t = team1.f + team1.s;
	team2.t = team2.f + team2.s;

	if (team1.t > team2.t) {
		std::cout << 0;
		return 0;
	} else if (match_type == 1) {
		if (team1.t == team2.t && team1.s <= team2.f)
			answer = 1;
		else if (team2.t > team1.t)
			answer = team2.t - team1.t;

		if (team1.t + answer == team2.t && team1.s + answer <= team2.f)
			answer++;
	} else {
		if (team1.t == team2.t && team1.f <= team2.s)
			answer = 1;
		else if (team2.t > team1.t)
			answer = team2.t - team1.t;

		if (team1.t + answer == team2.t && team1.f <= team2.s)
			answer++;
	}

	std::cout << answer;
}

//0:0 0:0 1
//1

//0:2 0:3 1
//5

//0:2 0:3 2
//6

//2:2 1:1 2
//0

//5:2 0:5 1
//3