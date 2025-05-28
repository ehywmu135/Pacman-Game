#include "pacman.h"

void pacman::move(char visited)
{
	Point& body = this->getBody();
	body.draw(' ');//Erase the pacman figure at it's last positon
	body.move(this->getCurrentDirection(),this->getFigure());
	body.draw(this->getFigure());
}

//gets the direction from the pressed key
int pacman::getDirectionFromKey(char key)const
{
	string arrowKeys = this->getArrowKeys();
	for (int i = 0; i < NUM_KEYS; i++)
	{
		if (key == arrowKeys[i])//if relevant key return it
			return i;
	}
	return EOF;
}