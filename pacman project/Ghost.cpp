#include "ghost.h"

void ghost::move(char visited)
{
	Point& body = this->getBody();
	body.draw(visited);
	body.move(this->getDirectionFromKey(),this->getFigure());
	body.draw(this->getFigure());	
}
//random direction for ghost,not smart moving
int ghost::getDirectionFromKey()const
{
	return rand() % 10;
}