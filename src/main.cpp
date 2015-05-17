// main.cpp

#include "platforms/terminal/term_game.h"

#include <iostream>

int main(int argc, char** argv)
{
	// Seed the starting randomization
	srand (time(NULL));

	TermGame game = TermGame();
	game.start();

	return 0;
}


