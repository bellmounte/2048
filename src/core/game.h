// game.h

#ifndef __GAME_H__
#define __GAME_H__

#include "game_board.h"

class Game
{
	public:
		Game();
		~Game();
		void startGame();
		void handleInput(Direction input);
		bool isGameOver();
	private:
		GameBoard game_board;
		bool in_progress;
};

#endif
