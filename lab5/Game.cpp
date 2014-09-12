#include "Game.h"

void Game::addRoom(Room* r)
{
	rooms.push_back(r);	
}
void Game::inputPrincess(int f)
{
	rooms[f]->princess();
}
void Game::inputDemon(int f)
{
	rooms[f]->demon();
}
void Game::getCommand(void)
{
	string go, direction;
	cin >> go >> this->command;
}
int Game::goToNext(void)
{
	if(command == "east")
		return rooms[now]->East();
	else if(command == "west")
		return rooms[now]->West();
	else if(command == "south")
		return rooms[now]->South();
	else if(command == "north")
		return rooms[now]->North();
	else if(command == "up")
		return rooms[now]->Up();
	else if(command == "down")
		return rooms[now]->Down();
	else{
		cout << "wrong command!" << endl;
		return 0;
	}
}
void Game::changeTag(int t)
{
	now = t;
}
int Game::whatHappened(int meet)
{
	if(!rooms[now]->getState()){
		rooms[now]->printInfo();
		return 0;
	}
	else if(rooms[now]->getState()==1){
		if(!meet){
		cout << "congratulation! You find the princess!" << endl;
		cout << "The process is going to leave with the you" << endl;
		}
		rooms[now]->printInfo();
		return 1;		 
	}
	else if(rooms[now]->getState()==-1){
		cout << "Oops! There is a monster! " << endl;
		cout << "GAME OVER" << endl;
		return -1;
	}

}
