#ifndef _THEPACMANGAME_H_
#define _THEPACMANGAME_H_
#include "io_utils.h"
#include "pacman.h"
#include "Ghost.h"
#include "Board.h"
enum {INIT_SCORE,DEFAULT_KEY,NEW_GAME = 1, NUM_OF_GHOSTS,NUM_OF_ENTITIES = 3, INIT_LIVES = 3,PRINT_INSTRUCTIONS = 8,END_GAME=9
	,ESC = 27,MAX_SCORE = 1716,BREAD_CRUMB='.',EMPTY = ' ',PACMAN = '@',GHOST = '$' };
class ThePacmanGame
{
	Entity** entities;//Pacman+Ghosts
	Board board;
	int numOfGhosts;
	int lives;
	int score = 0;//initial value
	bool gamePaused = false;
	bool clash = false;
public:
	ThePacmanGame() {}
	ThePacmanGame(const ThePacmanGame& other);
	void init();
	void run();
	void updateCellAndScore();
	void pauseGame(char KEY);
	bool isGameOver()const;
	bool isPlayerWon()const;
	void printMenuAndStartGame(ThePacmanGame& game)const;
	void printInstructions()const;
	char locationVisited(Point position)const;
	void resetEntitiesPosition();
	bool moveAndHandleClash(Entity& entity,char ghostVisited);
	void gameNotPaused(char& key, bool& move);
	Entity** getEntities() const;
	const ThePacmanGame& operator=(const ThePacmanGame& other);
	~ThePacmanGame();
	
};

#endif
#pragma once
