// game_board.h

#ifndef __GAME_BOARD_H__
#define __GAME_BOARD_H__

#include "config.h"
#include "game_board_slot.h"

enum Direction { UP, DOWN, LEFT, RIGHT };

class GameBoard
{
	public:
		GameBoard();
		~GameBoard();
		void performMove(Direction direction);
		bool isGameOver();
		int getScore_lastMove();
	protected:
		GameBoardSlot board[ROWS][COLUMNS];
	private:
		int score_last_move;
		void fillRandomEmptySlot();
		bool performMove_vertical(Direction direction);
		bool performMove_horizontal(Direction direction);
		void performMove_slots(int current_row, int current_col, int next_row, int next_col);
};

#endif
