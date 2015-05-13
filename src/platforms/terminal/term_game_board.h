// term_game_board.h

#ifndef __TERM_GAME_BOARD_H__
#define __TERM_GAME_BOARD_H__

#include "../../game_board.h"
#include "output.h"

class TermGameBoard : public GameBoard {
	public:
		void print();
};

#endif
