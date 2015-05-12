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
		void print();
		void perform_move(Direction direction);
		bool is_game_over();
	private:
		int random_number(int max);
		void fillRandomEmptySlot();
};

#endif
