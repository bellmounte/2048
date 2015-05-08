// game_board_slot.cpp

#include "game_board_slot.h"

bool _is_empty = true;

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
