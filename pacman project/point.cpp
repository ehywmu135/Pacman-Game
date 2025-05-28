#include "point.h"

void Point::draw(char ch) {
	gotoxy(x, y);
	cout << ch << endl;
}

// checks and update the location of the entities body by the pressed key of the player
void Point::move(int dir,char c)
{
	switch (dir) {
	case UP: // UP
	case up:
		if (y != 1)
			--y;
		else if (((x == 39) || (x == 40)) && (c == '@'))//pacman in the upper tunnel
			y = 22;
		break;
	case DOWN: // DOWN
	case down:
		if (y != 22)
			y++;
		
		else if (((x == 39) || (x == 40)) && (c == '@'))//pacman in the down tunnel
			y = 1;
		break;
	case LEFT: // LEFT
	case Left:
		if(x!=1)
		--x;
		else if (y==12 && c == '@')//pacman in the left tunnel
			x = 78;
		break;
	case RIGHT: // RIGHT
	case Right:
		if(x!=78)
		++x;
		else if (y == 12 && c == '@')//pacman in the up tunnel
		{
			x = 1;
		}
		break;
	case STOP:
	case stop:
		break;
	}
}