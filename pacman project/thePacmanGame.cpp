#include "thePacmanGame.h"

//init the game
void ThePacmanGame::init()
{
	// the entities array holds pacman in the first cell and inthe other cells ghosts
	cout << "Please enter number of ghosts" << endl;
	cin >> numOfGhosts;
	system("cls");
	entities = new Entity * [numOfGhosts + 1];
	entities[0] = new pacman();
	for (int i = 1; i <= numOfGhosts; i++)
	{
		entities[i] = new ghost(rand()%60+10, rand() % 15 + 10);//initial random values
	}

	lives = INIT_LIVES;
	score = INIT_SCORE;

	board.initBoard();
	board.printBoard();
}
//checks if the pacman eat bread crumb and if so, put empty char there and update the score
void ThePacmanGame::updateCellAndScore()
{
	char visited = locationVisited(entities[0]->getBody());
	if (visited == BREAD_CRUMB)
	{
		this->score++;
		gotoxy(7, 24);
		cout << this->score;
		this->board.getBoard()[this->entities[0]->getBody().getY()][this->entities[0]->getBody().getX()] = EMPTY;
	}

}
//checks if the pacman eat bread crumb
char ThePacmanGame::locationVisited(Point position)const
{
	char visited = EMPTY;
	if (this->board.getBoard()[position.getY()][position.getX()] == BREAD_CRUMB)
		visited = BREAD_CRUMB;
	return visited;
}

void ThePacmanGame::run()
{
	char key = DEFAULT_KEY;
	int dir;
	bool move = true;
	char ghost1Visited, ghost2Visited;
	do {
		hideCursor();
		if (_kbhit())
		{
			key = _getch();
			pauseGame(key);//stop and continue the game
			if ((dir = entities[0]->getDirectionFromKey(key)) != EOF)//if the direction is legal
				entities[0]->setDirection(dir);
		}

		if (!this->gamePaused)
		{
			gameNotPaused(key, move);//play until not paused
		}

	} while (!isGameOver() && !isPlayerWon());

	gotoxy(0, 26);
	if (this->isPlayerWon())
		cout << "Congratulations, you won! (Press any key to continue to main menu)" << endl << endl;

	if (this->isGameOver())
		cout << "Sorry, you lose. (Press any key to continue to main menu)" << endl << endl;

	_getch();//for the next player decision
	system("cls");
}

//checks if pause key pressed and handle with it
void ThePacmanGame::pauseGame(char KEY) {
	if (KEY == ESC)
	{
		gotoxy(0, 27);
		if (this->gamePaused)
		{
			this->gamePaused = false;
			cout << "                                            ";
		}
		else
		{
			this->gamePaused = true;
			cout << "Game paused, to continue please press ESC...";
		}
	}
}


bool ThePacmanGame::isGameOver()const
{
	return (this->lives == 0);
}
bool ThePacmanGame::isPlayerWon()const
{
	return (this->score == MAX_SCORE);
}


void ThePacmanGame::printMenuAndStartGame(ThePacmanGame& game)const
{
	srand(time(NULL));
	int playerChoice;

	do
	{
		cout << "Pacman menu: " << endl;
		cout << "(1) Start a new game" << endl;
		cout << "(8) Present instructions and keys" << endl;
		cout << "(9) EXIT" << endl;
		cin >> playerChoice;
		switch (playerChoice)
		{
		case PRINT_INSTRUCTIONS:
			system("cls");
			this->printInstructions();
			break;
		case NEW_GAME:
			system("cls");
			game.init();
			game.run();
			break;
		case END_GAME:
			return;
			break;
		default:
			cout << "Error: invalid choice was selected." << endl;
			break;
		}
	} while (playerChoice != END_GAME);
}

void ThePacmanGame::printInstructions()const
{
	cout << "Instructions and keys:" << endl;
	cout << "The player controls Pac-Man, who must eat all the dots inside an enclosed maze while avoiding the ghosts."
		<< endl << "\nPlaying keys: \nW/w - Moving up.\nX/x - Moving down.\nD/d - Moving right.\nA/a - Moving left.\nS/s - Stop"
		<< endl << endl;
}


void ThePacmanGame::resetEntitiesPosition()
{
	for (int j = 0; j < NUM_OF_ENTITIES; j++)
	{
		entities[j]->getBody().draw(EMPTY);//puts empty cell where the pacman visited
		entities[j]->getBody().setX(entities[j]->getInitialPos().getX());//init the entity place
		entities[j]->getBody().setY(entities[j]->getInitialPos().getY());
		if (j == 0)//if pacman
		{
			entities[j]->setDirection(DEFAULT_KEY);//set the direction
			entities[j]->getBody().draw(PACMAN);//prints the pacman in the initial position
		}
		else
			entities[j]->getBody().draw(GHOST);
	}
}

bool ThePacmanGame::moveAndHandleClash(Entity& entity, char ghostVisited)
{
	if (entity.getFigure() == PACMAN)
	{
		entity.move(EMPTY);//prints space
		for (int i = 1; i <= NUM_OF_GHOSTS; i++)
		{
			if ((entities[0]->getBody() == entities[i]->getBody()))//checks if the pacman clashed with one of the ghosts
			{
				this->lives--;
				gotoxy(29, 24);
				cout << lives;
				resetEntitiesPosition();
				return true;
			}
		}
		return false;
	}
	else
	{
		entity.move(ghostVisited);
		if (entity.getBody() == entities[0]->getBody())//Checks if one of the ghosts clashed with the pacman
		{
			this->lives--;
			gotoxy(29, 24);
			cout << lives;
			resetEntitiesPosition();
			return true;
		}
	}
	return false;
}
ThePacmanGame::~ThePacmanGame()
{
	for (int i = 0; i < NUM_OF_ENTITIES; i++)
	{
		delete entities[i];
	}
}

void ThePacmanGame::gameNotPaused(char& key, bool& move)
{
	if (key != DEFAULT_KEY)//wait until press key
	{
		for (int i = 0; i < NUM_OF_ENTITIES; i++)
		{
			if (entities[i]->getFigure() == PACMAN || move == true) {
				moveAndHandleClash(*entities[i], locationVisited(entities[i]->getBody()));//move and hand clashes
			}
		}
		move = (move == true) ? false : true;
		updateCellAndScore();
		Sleep(100);
	}
	else//prints the entitites before the game starts
	{
		for (int j = 0; j < NUM_OF_ENTITIES; j++)
		{
			entities[j]->getBody().draw(entities[j]->getFigure());
		}
	}
}

const ThePacmanGame& ThePacmanGame::operator=(const ThePacmanGame& other)
{
	if (this->entities != other.entities)
	{
		for (int i = 0; i < numOfGhosts+1; i++)
		{
			delete entities[i];
		}
		delete entities;
		
		entities = new Entity*[other.numOfGhosts + 1];
		for (int i = 0; i < numOfGhosts + 1; i++)
		{
			 entities[i] = other.getEntities()[i];
			 ///add assignment for all fields
		}
	}
	return *this;
}
Entity** ThePacmanGame::getEntities() const
{
	return entities;
}

ThePacmanGame::ThePacmanGame(const ThePacmanGame& other)
{
	entities = new Entity * [other.numOfGhosts];
	for (int i = 0; i < numOfGhosts + 1; i++)
	{
		entities[i] = other.getEntities()[i];
		///add assignment for all fields
	}
	board = other.board;
	numOfGhosts = other.numOfGhosts;
	lives = other.lives;
	score = other.score;
	gamePaused = other.gamePaused;
	clash = other.clash;
}
