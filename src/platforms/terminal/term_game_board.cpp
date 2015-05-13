// term_game_board.cpp

#include <iostream>
#include <iomanip>
#include "term_game_board.h"


void TermGameBoard::print ()
{
	// Is there a better way to do this in C++? Preferably using a one liner.
	Output output;
	output.clear();

	for (int row = 0; row < ROWS; ++row) {
		for (int col = 0; col < COLUMNS; ++col) {
			std::cout << " | " << std::setw(5);
			if (board[row][col].isEmpty()) {
				std::cout << " ";
			} else {
				std::cout << board[row][col].getTile().getValue();
			}
		}
		std::cout << " |" << std::endl;
	}
	std::cout << std::endl;
}
