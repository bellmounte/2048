// game_board_tile.cpp

#include "game_board_tile.h"

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
