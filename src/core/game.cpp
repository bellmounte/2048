// game.cpp

#include "game.h"

Game::Game ()
{
	game_board = GameBoard();

	in_progress = true;
}

Game::~Game ()
{
	in_progress = false;
}

void Game::handleInput(Direction input)
{
	if (in_progress) {
		game_board.perform_move(input);
	}
}

bool Game::isGameOver()
{
	if (!in_progress) {
		return true;
	}

	return game_board.is_game_over();
}
