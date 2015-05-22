// game.hpp

#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "core/game_board.hpp"

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
