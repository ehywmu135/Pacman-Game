#ifndef _GHOST_H_
#define _GHOST_H_
#include "entity.h"

class ghost : public Entity
{

public:
	ghost(int x,int y) : Entity(x,y,'$',0) {};
	void move(char visited);
	int getDirectionFromKey()const;
	~ghost() {};
};

#endif#pragma once