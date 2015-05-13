// game_board_tile.h

#ifndef __GAME_BOARD_TILE_H__
#define __GAME_BOARD_TILE_H__

#include "config.h"

class GameBoardTile
{
	public:
		GameBoardTile();
		GameBoardTile(int value);
		~GameBoardTile();
		int getValue();
		void setValue();
		void doubleValue();
	private:
		int _value;
};

#endif
