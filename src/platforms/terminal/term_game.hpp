// term_game.hpp

#ifndef __TERM_GAME_H__
#define __TERM_GAME_H__

#include "core/game.hpp"
#include "term_game_board.hpp"

class TermGame : public Game {
	public:
		void start();
		Direction getInput();
		void print();
		TermGameBoard& getGameBoard() {
			return game_board;
		}
	protected:
		TermGameBoard game_board;
	private:
		bool in_progress;
};

#endif
