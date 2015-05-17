// game_board_slot.h

#ifndef __GAME_BOARD_SLOT_H__
#define __GAME_BOARD_SLOT_H__

#include "game_board_tile.h"

class GameBoardSlot
{
	public:
		GameBoardSlot();
		~GameBoardSlot();
		bool isEmpty();
		bool hasSameValueTile(GameBoardSlot slot);
		void initializeTile();
		void setTile(int value);
		void doubleTile();
		void removeTile();
		GameBoardTile getTile();
	private:
		bool _is_empty;
		GameBoardTile _tile;
};

#endif
