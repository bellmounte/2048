// output.cpp

#include "output.h"

#include <iostream>

void Output::clear ()
{
	std::cout << "\033[H\033[2J" << std::flush;
}
