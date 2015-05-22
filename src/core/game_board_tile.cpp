// game_board_tile.cpp

#include "core/game_board_tile.hpp"

GameBoardTile::GameBoardTile()
{
	_value = 1;
}

GameBoardTile::GameBoardTile(int value)
{
	_value = value;
}

GameBoardTile::~GameBoardTile()
{
	_value = 0;
}

int GameBoardTile::getValue ()
{
	return _value;
}

void GameBoardTile::doubleValue()
{
	_value *= 2;
}
