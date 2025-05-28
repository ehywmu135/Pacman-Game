#include "Board.h"


Board::Board()
{
	this->initBoard();
}
Board::~Board()
{
	for (int x = 0; x < HEIGHT; x++) {
		delete[] board[x];
	}
	delete[] board;
}
void Board::printBoard() const
{
	for (int x = 0; x < HEIGHT - 1; x++) {
		for (int y = 0; y < WIDTH; y++) {
			cout << board[x][y];
		}
		cout << '\n';
	}
	gotoxy(0, 24);
	cout << "Score: 0 " << "   " << "number of lives: 3" << "   ";
}

char** Board::getBoard() const
{
	return board;
}
void Board::initBoard()
{
	/*board = new char* [WIDTH];
	for (int x = 0; x < HEIGHT; x++) {
		board[x] = new char[WIDTH];
	}

	int row, col;
	//init the relevant place on board to relevant char
	for (row = 0; row < HEIGHT - 1; row++)
	{
		for (col = 0; col < WIDTH; col++)
		{
			if ((row == 0 && col == WIDTH/2) || (row == HEIGHT - 2 && col == WIDTH / 2)
				|| (row == 0 && col == (WIDTH / 2)-1) || (row == HEIGHT - 2 && col == (WIDTH / 2) - 1))//"Portals" logic implement
				board[row][col] = PACMAN_TUNNEL;

			else if ((row == HEIGHT/2 && col == 0) || (row == HEIGHT / 2 && col == WIDTH-1))
				board[row][col] = PACMAN_WALL;

			else if (row == 0 || row == HEIGHT - 2 || col == 0 || col == WIDTH - 1)
				board[row][col] = WALL;

			else
				board[row][col] = BREAD_CRUMBS;
		}

	}*/
	ifstream boardGame("pacman_1.screen.txt");

	if (!boardGame) {
		cout << "Error, file couldn't be opened" << endl;
		return;
	}

	board = new char* [WIDTH];
	for (int x = 0; x < HEIGHT; x++)
	{
		board[x] = new char[WIDTH];
	}

	for (int row = 0; row < HEIGHT; row++) {

		for (int column = 0; column < WIDTH; column++)
		{
			boardGame >> this->board[row][column];

			if (!boardGame) {
				cout << "Error reading file for element " << row << "," << column << endl;
			}
		}
	}

}
const Board& Board::operator=(const Board& other)
{
	if (this != &other)
	{
		for (int row = 0; row < HEIGHT; row++) {

			for (int column = 0; column < WIDTH; column++) 
			{
				this->board[row][column] = other.board[row][column];
			}
		}
	}
	return *this;
}
Board::Board(const Board& other)
{
	board = new char* [WIDTH];
	for (int x = 0; x < HEIGHT; x++) 
	{
		board[x] = new char[WIDTH];
	}
	for (int row = 0; row < HEIGHT; row++) 
	{
		for (int column = 0; column < WIDTH; column++)
		{
			this->board[row][column] = other.board[row][column];
		}
	}
}