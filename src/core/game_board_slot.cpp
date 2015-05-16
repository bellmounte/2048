// game_board_slot.cpp

#include "core/game_board_slot.h"
#include "core/util.h"

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

bool GameBoardSlot::hasSameValueTile(GameBoardSlot slot)
{
	return (_tile.getValue() == slot.getTile().getValue());
}

void GameBoardSlot::initializeTile()
{
	int k = util::random(10);
	if (k < 3) {
		setTile(2);
	} else {
		setTile(1);
	}
}

void GameBoardSlot::setTile (int value)
{
	_tile = GameBoardTile(value);
	_is_empty = false;
}

void GameBoardSlot::doubleTile()
{
	_tile.doubleValue();
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
