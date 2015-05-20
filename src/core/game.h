// game.h

#ifndef __GAME_H__
#define __GAME_H__

#include "game_board.h"

class Game
{
	public:
		Game();
		~Game();
		virtual GameBoard& getGameBoard() = 0;
		void start();
		void handleInput(Direction input);
		bool isGameOver();
		int getScore();
	protected:
		GameBoard game_board;
	private:
		bool in_progress;
		int game_score;
};

#endif
