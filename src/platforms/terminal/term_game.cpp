// term_game_board.cpp

#include "term_game.h"

#include <iostream>
#include <string>

Direction TermGame::getInput()
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
		return getInput();
	}
}

void TermGame::start()
{
	bool in_progress = true;

	while (in_progress) {

		// Print the 2048 Board
		game_board.print();

		// Get user input for next move.
		Direction input = getInput();

		// Perform a move based on the given user input.
		game_board.perform_move(input);

		// Check to see if there are any valid moves left.
		in_progress = !(game_board.is_game_over());

	}
}
