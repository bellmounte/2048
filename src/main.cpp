// main.cpp

#include <iostream>

#include "platforms/terminal/term_game.h"

int main(int argc, char** argv)
{

	// Seed the starting randomization
	srand (time(NULL));

	std::cout << "2048++" << std::endl;

	TermGame game = TermGame();
	game.start();

	std::cout << "Thanks for playing 2048++" << std::endl;

	return 0;
}


