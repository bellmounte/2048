// game_board_slot.hpp

#ifndef __GAME_BOARD_SLOT_HPP__
#define __GAME_BOARD_SLOT_HPP__

#include "core/game_board_tile.hpp"

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
