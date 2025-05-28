#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "io_utils.h"

enum{UP = 0,up=1,DOWN = 2,down = 3,LEFT=4,Left=5,RIGHT=6,Right=7,STOP=8,stop=9};
class Point {
	int x, y;
public:
	Point(int x = 1, int y = 1) :x(x), y(y) {};
	void draw(char ch);
	void move(int direction,char c);
	int getX()const { return x; };
	void setX(int p)
	{
		x = p;
	};

	int getY()const { return y; }
	void setY(int p)
	{
		y = p;
	}
	bool operator==(const Point& other) const 
	{
		return x == other.x && y == other.y;
	}
};

#endif
