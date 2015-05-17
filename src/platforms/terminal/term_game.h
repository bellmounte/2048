// term_game.h

#ifndef __TERM_GAME_H__
#define __TERM_GAME_H__

#include "core/game.h"
#include "term_game_board.h"

class TermGame : public Game {
	public:
		void start();
		Direction getInput();
	protected:
		TermGameBoard game_board;
};

#endif
