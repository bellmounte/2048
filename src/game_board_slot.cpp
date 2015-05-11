// game_board_slot.cpp

#include "game_board_slot.h"

GameBoardSlot::GameBoardSlot ()
{
	_is_empty = true;
}

GameBoardSlot::~GameBoardSlot ()
{
}

bool GameBoardSlot::isEmpty ()
{
	return _is_empty;
}

void GameBoardSlot::setTile (int value)
{
	_tile = GameBoardTile(value);
	_is_empty = false;
}

void GameBoardSlot::removeTile ()
{
	_is_empty = true;
	// TODO: Clear the tile. Neither of these are working correctly.
	// _tile = NULL;
	// delete _tile;
}

GameBoardTile GameBoardSlot::getTile ()
{
	return _tile;
}
