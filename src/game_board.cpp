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

bool perform_move_vertical(Direction direction)
{
	bool valid_move = false;

	// Perform transforms
	for (int i = 0; i < COLUMNS; i++) {

		for (int j = 0; j < ROWS; j++) {
			int index = i + (COLUMNS * j);

			// If we have somehow gone past the board, break;
			if (index >= SLOTS) {
				break;
			}

			// If the slot is empty, continue.
			if (board[index] == 0) {
				continue;
			}

			do {
				int nextIndex = i + (COLUMNS * (j+1));

				// If the next index is past the board, break;
				if (nextIndex >= SLOTS) {
					break;
				}

				if (board[nextIndex] == 0) {
					// If the slot is empty, continue.
					j++;
				} else if (board[index] == board[nextIndex]) {
					board[index] = board[index] + board[nextIndex];
					board[nextIndex] = 0;
					valid_move = true;
					break;
				} else {
					break;
				}
			} while (j < ROWS);
		}


		// Perform Shifts
		for (int i = 0; i < COLUMNS; i++) {

			if (direction == UP) {
				int availableIndex = -1;
				for (int j = 0; j < ROWS; j++) {
					int index = i + (COLUMNS * j);

					// If we have somehow gone past the board, break;
					if (index >= SLOTS) {
						break;
					}

					if (board[index] == 0) {
						// Set first available index if one does not exist.
						if (availableIndex == -1) {
							availableIndex = index;
						}
						continue;
					} else {
						if (availableIndex == -1) {
							continue;
						} else {
							board[availableIndex] = board[index];
							board[index] = 0;
							availableIndex = availableIndex + COLUMNS;
							valid_move = true;
						}
					}
				}
			}
		}
	}

	return valid_move;
}

bool perform_move_horizontal(Direction direction)
{
	bool valid_move = false;
	for (int i = 0; i < ROWS; i++) {
	}
	return valid_move;
}


void GameBoard::perform_move(Direction direction)
{
	bool valid_move = false;
	switch (direction) {
		case DOWN:
		case UP:
			valid_move = perform_move_vertical(direction);
			break;
		case LEFT:
		case RIGHT:
			valid_move = perform_move_horizontal(direction);
			break;
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
