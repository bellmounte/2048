// game.h

#ifndef __GAME_H__
#define __GAME_H__

#include "game_board.h"

class Game
{
	public:
		Game();
		~Game();
		void start();
		void handleInput(Direction input);
		bool isGameOver();
		Direction getInput();
	protected:
		GameBoard game_board;
	private:
		bool in_progress;
};

#endif
