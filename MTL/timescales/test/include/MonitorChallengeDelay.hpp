#include "array"
#include "discrete_time.hpp"

template<typename T = int>
struct MonitorChallengeDelay {

	std::array<bool,1> states = std::array<bool,1>{0};
	std::array<bool,1> states_pre = std::array<bool,1>{0};

	std::array<interval_set<T>,1> tstates = std::array<interval_set<T>,1>{interval_set<T>()};
	std::array<interval_set<T>,1> tstates_pre = std::array<interval_set<T>,1>{interval_set<T>()};

	T now = 0;

	bool update(bool p, bool q){

		now = now + 1;
		states_pre = states;
		tstates_pre = tstates;

		tstates[0] = update_timed_since<T>(tstates[0], now, p, q, 60, 60);
		states[0] = (p or output_timed_since<T>(tstates[0], now));

		return output();
	}

	bool output(){
		return states[0];
	}
};