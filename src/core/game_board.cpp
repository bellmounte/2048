// game_board.cpp

#include <iostream>
#include <iomanip>
#include "game_board.h"

GameBoard::GameBoard ()
{
	// Set the initial board.
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLUMNS; ++j) {
			board[i][j] = GameBoardSlot();
		}
	}

	for (int i = 0; i < INITIAL_TILES; i++) {
		fillRandomEmptySlot();
	}
}

GameBoard::~GameBoard ()
{
	// TODO: Verify what needs to be destroyed.
	// delete[] board;
}

void GameBoard::fillRandomEmptySlot ()
{
	int openings_row[SLOTS];
	int openings_col[SLOTS];
	int openings_size = 0;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (board[i][j].isEmpty()) {
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
		board[opening_row][opening_col].initializeTile();
	}
}

// TODO: Move this method to a platform specific class.
void GameBoard::print ()
{
	system("clear");

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

int GameBoard::random_number (int max)
{
	return rand() % max;
}

bool GameBoard::perform_move_vertical(Direction direction)
{
	bool valid_move = false;

	// Perform transforms
	for (int col = 0; col < COLUMNS; col++) {

		for (int row = 0; row < ROWS; row++) {

			// If the slot is empty, continue.
			if (board[row][col].isEmpty()) {
				continue;
			}

			int current_row = row;

			while (row + 1 < ROWS) {

				int next_row = row + 1;

				if (board[next_row][col].isEmpty()) {
					// If the slot is empty, continue.
					row++;
				} else if (board[current_row][col].hasSameValueTile(board[next_row][col])) {
					board[current_row][col].doubleTile();
					board[next_row][col].removeTile();
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
				if (board[row][col].isEmpty()) {
					// Set first available index if one does not exist.
					if (available_row == -1) {
						available_row = row;
					}
				} else if (available_row != -1) {
					board[available_row][col].setTile(board[row][col].getTile().getValue());
					board[row][col].removeTile();
					available_row++;
					valid_move = true;
				}
			}
		}
	}

	return valid_move;
}

bool GameBoard::perform_move_horizontal(Direction direction)
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
		fillRandomEmptySlot();
	}
}

bool GameBoard::is_game_over()
{
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLUMNS; col++) {
			if (board[row][col].isEmpty()) {
				return false;
			}
		}
	}
	return true;
}
