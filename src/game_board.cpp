// game_board.cpp

#include <iostream>
#include "game_board.h"

// TODO: This will need to be moved out of the core GameBoard class.
#include "platforms/terminal/output.h"

// TODO: Need to convert this to use GameBoardSlots
int board[SLOTS] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

GameBoard::GameBoard ()
{
	// Get the first two nodes that will be 1
	int first = random_number(SLOTS);
	int second = random_number(SLOTS);

	// Ensure there are two different starting 1's
	while (second == first) {
		second = random_number(SLOTS);
	}

	// Set the first two ones
	// TODO: Set the slots to tiles.
	board[first] = 1;
	board[second] = 1;
}

GameBoard::~GameBoard ()
{
	// TODO: Verify what needs to be destroyed.
	// delete[] board;
}

// TODO: Move this method to a platform specific class.
void GameBoard::print ()
{
	// Is there a better way to do this in C++? Preferably using a one liner.
	Output output;
	output.clear();

	std::cout << "GameBoard Class Board:" << std::endl;
	for (int i = 0; i < SLOTS; i++) {
		std::cout << board[i] << " ";
		if ((i + 1) % COLUMNS == 0) {
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

int GameBoard::random_number (int max)
{
	return rand() % max;
}


void GameBoard::perform_move(Direction direction)
{
	bool valid_move = false;
	for (int i = 0; i < SLOTS - COLUMNS; i++) {
		switch (direction) {
			case UP:
				if (board[i] == board[COLUMNS + i] && board[i] != 0) {
					board[i] = 2 * board[i];
					board[COLUMNS + i] = 0;
					valid_move = true;
				} else if (board[i] == 0 && board[COLUMNS + i] != 0) {
					board[i] = board[COLUMNS + i];
					board[COLUMNS + i] = 0;
					valid_move = true;
				}
				break;
			case DOWN:
			case LEFT:
			case RIGHT:
				break;
		}
	}

	if (valid_move) {
		int openings[SLOTS];
		int openings_size = 0;
		for (int i = 0; i < SLOTS; i++) {
			if (board[i] == 0) {
				openings[openings_size++] = i;
			}
		}
		if (openings_size > 0) {
			board[openings[random_number(openings_size)]]= 1;
		}
	}
}

bool GameBoard::is_game_over()
{
	for (int i = 0; i < SLOTS; i++) {
		if (board[i] == 0) {
			return false;
		}
	}
	return true;
}
