// helloworld.cpp

#include <iostream>
#include <string>

#include "config.h"
#include "game_board.h"

int random_number (int max) {
	return rand() % max;
}

// Platform specific
Direction get_input ()
{
	std::cout << "Enter the shift direction [`up`, `down`, `left`, or `right`]: ";
	std::string input = "";
	getline(std::cin, input);

	if (input == "up" || input == "u") {
		return UP;
	} else if (input == "down" || input == "d") {
		return DOWN;
	} else if (input == "left" || input == "l") {
		return LEFT;
	} else if (input == "right" || input == "r") {
		return RIGHT;
	} else {
		std::cout << "Invalid input: [" << input << "], try again:" << std::endl;
		return get_input();
	}

}

int main(int argc, char** argv)
{
	GameBoard* game_board = new GameBoard();

	bool inProgress = true;

	// Seed the starting randomization
	srand (time(NULL));

	std::cout << "2048++" << std::endl;

	// Main game loop
	while (inProgress) {

		// Print the 2048 Board
		game_board->print();

		// Get user input for next move.
		Direction input = get_input();

		// Perform a move based on the given user input.
		game_board->perform_move(input);

		// Check to see if there are any valid moves left.
		inProgress = !(game_board->is_game_over());

	}

	return 0;
}


