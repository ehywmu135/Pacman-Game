#ifndef _BOARD_H_
#define _BOARD_H_
#include "io_utils.h"
enum { WIDTH = 80, HEIGHT = 25,PACMAN_WALL = '|',PACMAN_TUNNEL='_', WALL = '#',BREAD_CRUMBS='.' };
class Board {
	
	char** board;
public:
	Board();
	Board(const Board& other);
	~Board();
	void printBoard() const;
	char** getBoard() const;
	void initBoard();
	const Board& operator=(const Board& other);
};


#endif