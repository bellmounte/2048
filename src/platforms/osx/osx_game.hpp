// osx_game.hpp

#ifndef __OSX_GAME_H__
#define __OSX_GAME_H__

#include "core/game.hpp"
#include "osx_game_board.hpp"

class OSXGame : public Game {
	public:
		void start();
		OSXGameBoard& getGameBoard() {
			return game_board;
		}
	protected:
		void render();
		OSXGameBoard game_board;
};

#endif
