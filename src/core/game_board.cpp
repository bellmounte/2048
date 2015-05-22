// game_board.cpp

#include "core/game_board.hpp"

#include "core/util.hpp"

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

	// Set initial value for the move score.
	score_last_move = 0;
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
		int index = util::random(openings_size);
		int opening_row = openings_row[index];
		int opening_col = openings_col[index];
		board[opening_row][opening_col].initializeTile();
	}
}

int GameBoard::getScore_lastMove () {
	return score_last_move;
}

void GameBoard::performMove_slots(int current_row, int current_col, int next_row, int next_col)
{
	// Calculate the score of merging these tiles.
	int tile_value = board[current_row][current_col].getTile().getValue();
	score_last_move += (tile_value - 1) * util::pow2(tile_value);

	// Perform the move.
	board[current_row][current_col].doubleTile();
	board[next_row][next_col].removeTile();
}

bool GameBoard::performMove_vertical(Direction direction)
{
	bool valid_move = false;

	// Perform transforms
	for (int col = 0; col < COLUMNS; col++) {
		if (direction == UP) {
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
						performMove_slots(current_row, col, next_row, col);
						valid_move = true;
						break;
					} else {
						break;
					}
				}
			}
		} else if (direction == DOWN) {
			for (int row = ROWS - 1; row > 0; row--) {
				// If the slot is empty, continue.
				if (board[row][col].isEmpty()) {
					continue;
				}

				int current_row = row;

				while (row - 1 >= 0) {
					int next_row = row - 1;

					if (board[next_row][col].isEmpty()) {
						// If the slot is empty, continue.
						row--;
					} else if (board[current_row][col].hasSameValueTile(board[next_row][col])) {
						performMove_slots(current_row, col, next_row, col);
						valid_move = true;
						break;
					} else {
						break;
					}
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
		} else if (direction == DOWN) {
			for (int row = ROWS - 1; row >= 0; row--) {
				if (board[row][col].isEmpty()) {
					// Set first available index if one does not exist.
					if (available_row == -1) {
						available_row = row;
					}
				} else if (available_row != -1) {
					board[available_row][col].setTile(board[row][col].getTile().getValue());
					board[row][col].removeTile();
					available_row--;
					valid_move = true;
				}
			}
		}
	}

	return valid_move;
}

bool GameBoard::performMove_horizontal(Direction direction)
{
	bool valid_move = false;
	score_last_move = 0;

	// Perform transforms
	for (int row = 0; row < ROWS; row++) {
		if (direction == LEFT) {
			for (int col = 0; col < ROWS; col++) {
				// If the slot is empty, continue.
				if (board[row][col].isEmpty()) {
					continue;
				}

				int current_col = col;

				while (col + 1 < COLUMNS) {

					int next_col = col + 1;

					if (board[row][next_col].isEmpty()) {
						// If the slot is empty, continue.
						col++;
					} else if (board[row][current_col].hasSameValueTile(board[row][next_col])) {
						performMove_slots(row, current_col, row, next_col);
						valid_move = true;
						break;
					} else {
						break;
					}
				}
			}
		} else if (direction == RIGHT) {
			for (int col = COLUMNS - 1; col > 0; col--) {
				// If the slot is empty, continue.
				if (board[row][col].isEmpty()) {
					continue;
				}

				int current_col = col;

				while (col - 1 >= 0) {
					int next_col = col - 1;

					if (board[row][next_col].isEmpty()) {
						// If the slot is empty, continue.
						col--;
					} else if (board[row][current_col].hasSameValueTile(board[row][next_col])) {
						performMove_slots(row, current_col, row, next_col);
						valid_move = true;
						break;
					} else {
						break;
					}
				}
			}
		}
	}

	// Perform Shifts
	for (int row = 0; row < ROWS; row++) {

		int available_col = -1;

		if (direction == LEFT) {
			for (int col = 0; col < COLUMNS; col++) {
				if (board[row][col].isEmpty()) {
					// Set first available index if one does not exist.
					if (available_col == -1) {
						available_col = col;
					}
				} else if (available_col != -1) {
					board[row][available_col].setTile(board[row][col].getTile().getValue());
					board[row][col].removeTile();
					available_col++;
					valid_move = true;
				}
			}
		} else if (direction == RIGHT) {
			for (int col = COLUMNS - 1; col >= 0; col--) {
				if (board[row][col].isEmpty()) {
					// Set first available index if one does not exist.
					if (available_col == -1) {
						available_col = col;
					}
				} else if (available_col != -1) {
					board[row][available_col].setTile(board[row][col].getTile().getValue());
					board[row][col].removeTile();
					available_col--;
					valid_move = true;
				}
			}
		}
	}

	return valid_move;
}


void GameBoard::performMove(Direction direction)
{
	bool valid_move = false;
	switch (direction) {
		case DOWN:
		case UP:
			valid_move = performMove_vertical(direction);
			break;
		case LEFT:
		case RIGHT:
			valid_move = performMove_horizontal(direction);
			break;
	}

	if (valid_move) {
		fillRandomEmptySlot();
	}
}

bool GameBoard::isGameOver()
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
