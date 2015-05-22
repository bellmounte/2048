// game_board_tile.hpp

#ifndef __GAME_BOARD_TILE_HPP__
#define __GAME_BOARD_TILE_HPP__

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
