#include "entity.h"
void Entity::setArrowKeys(const char* keys)
{ // "wWxXaAdDsS", set the arrow keys
	arrowKeys[0] = keys[0];
	arrowKeys[1] = keys[1];
	arrowKeys[2] = keys[2];
	arrowKeys[3] = keys[3];
	arrowKeys[4] = keys[4];
	arrowKeys[5] = keys[5];
	arrowKeys[6] = keys[6];
	arrowKeys[7] = keys[7];
	arrowKeys[8] = keys[8];
	arrowKeys[9] = keys[9];
}

Point& Entity::getBody() 
{
	return body;
}
Point& Entity::getInitialPos() 
{
	return initialPos;
}
string Entity::getArrowKeys() const
{
	return arrowKeys;
}

void Entity::setFigure(const char c)
{
	figure = c;
}
int Entity::getDirectionFromKey(char key)const { return 0; };
int Entity::getDirectionFromKey()const { return 0; };
int Entity::getCurrentDirection() const
{
	return direction;
}
void Entity::setDirection(int dir) {
	direction = dir;
}

char Entity::getFigure()const {
	return figure;
}

