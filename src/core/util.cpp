// util.cpp

#include "util.h"

#include <iostream>

namespace util
{
	int random (int max) {
		return util::random(max, 0);
	}

	int random (int max, int min) {
		return rand() % (max - min) + min;
	}
}
