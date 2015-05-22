// util.cpp

#include "core/util.hpp"

#include <iostream>

namespace util
{
	int random (int max) {
		return util::random(max, 0);
	}

	int random (int max, int min) {
		return rand() % (max - min) + min;
	}

	int pow2 (unsigned power) {
		return 1 << power;
	}
}
