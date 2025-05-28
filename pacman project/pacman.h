#ifndef _PACMAN_H_
#define _PACMAN_H_
#include "entity.h"

class pacman: public Entity
{

public:
	pacman() : Entity(1,1,'@',0){}
	void move(char visited);
	int getDirectionFromKey(char key)const;
	~pacman();
};

#endif#pragma once