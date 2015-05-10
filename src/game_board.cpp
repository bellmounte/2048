// game_board.cpp

#include <iostream>
#include "game_board.h"

// TODO: This will need to be moved out of the core GameBoard class.
#include "platforms/terminal/output.h"

// TODO: Need to convert this to use GameBoardSlots
int board[ROWS][COLUMNS];

GameBoard::GameBoard ()
{
	// Set the initial board.
	// TODO: Set these to GameBoardSlots
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLUMNS; ++j) {
			board[i][j] = 0;
		}
	}

	// Get the first two nodes that will be 1
	int rand_row_first = random_number(ROWS);
	int rand_row_second = random_number(ROWS);
	int rand_col_first = random_number(COLUMNS);
	int rand_col_second = random_number(COLUMNS);

	// Ensure there are two different starting 1's
	while (rand_row_first == rand_row_second && rand_col_first == rand_col_second) {
		rand_row_second = random_number(ROWS);
		rand_col_second = random_number(COLUMNS);
	}

	// Set the first two ones
	// TODO: Set the slots to tiles.
	board[rand_row_first][rand_col_first] = 1;
	board[rand_row_second][rand_col_second] = 1;
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

	for (int row = 0; row < ROWS; ++row) {
		for (int col = 0; col < COLUMNS; ++col) {
			std::cout << board[row][col] << " ";
		}
		std::cout << std::endl;
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
	for (int col = 0; col < COLUMNS; col++) {

		for (int row = 0; row < ROWS; row++) {

			// If the slot is empty, continue.
			if (board[row][col] == 0) {
				continue;
			}

			int current_row = row;

			while (row + 1 < ROWS) {

				int next_row = row + 1;

				if (board[next_row][col] == 0) {
					// If the slot is empty, continue.
					row++;
				} else if (board[current_row][col] == board[next_row][col]) {
					board[current_row][col] = board[current_row][col] + board[next_row][col];
					board[next_row][col] = 0;
					valid_move = true;
					break;
				} else {
					break;
				}
			}
		}
	}

	// Perform Shifts
	for (int col = 0; col < COLUMNS; col++) {

		int available_row = -1;

		if (direction == UP) {
			for (int row = 0; row < ROWS; row++) {
				if (board[row][col] == 0) {
					// Set first available index if one does not exist.
					if (available_row == -1) {
						available_row = row;
					}
				} else if (available_row != -1) {
					board[available_row][col] = board[row][col];
					board[row][col] = 0;
					available_row++;
					valid_move = true;
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
		int openings_row[SLOTS];
		int openings_col[SLOTS];
		int openings_size = 0;

		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLUMNS; j++) {
				if (board[i][j] == 0) {
					openings_row[openings_size] = i;
					openings_col[openings_size] = j;
					openings_size++;
				}
			}
		}

		if (openings_size > 0) {
			int index = random_number(openings_size);
			int opening_row = openings_row[index];
			int opening_col = openings_col[index];
			board[opening_row][opening_col]= 1;
		}
	}
}

bool GameBoard::is_game_over()
{
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLUMNS; col++) {
			if (board[row][col] == 0) {
				return false;
			}
		}
	}
	return true;
}
