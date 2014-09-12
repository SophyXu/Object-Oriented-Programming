#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "Room.h"
#include "Game.h"
using namespace std;

int main()
{
	//initialize
	int meet = 0, t, w, ran1, ran2;
	Room temp("null", 0, 0, 0, 0, 0, 0, 0, 0); // fill in vector room[0]
	Room A("lobby", 1, 4, 2, 0, 3, 0, 0, 0);
	Room B("Bob", 2, 1, 0, 0, 0, 0, 0, 0);
	Room C("Caleb", 3, 0, 0, 1, 0, 0, 0, 0);
	Room D("David", 4, 5, 1, 0, 0, 6, 0, 0);
	Room E("Ellen", 5, 0, 4, 0, 0, 0, 0, 0);
	Room F("Fell", 6, 0, 8, 0, 7, 0, 4, 0);
	Room G("George", 7, 0, 0, 6, 0, 0, 0, 0);
	Room H("Hellen", 8, 6, 9, 0, 0, 0, 0, 1);
	Room I("Ille", 9, 8, 0, 0, 0, 0, 0, 0);
	Game play;
	play.addRoom(temp);
	play.addRoom(A);
	play.addRoom(B);
	play.addRoom(C);
	play.addRoom(D);
	play.addRoom(E);
	play.addRoom(F);
	play.addRoom(G);
	play.addRoom(H);
	play.addRoom(I);
	
	srand(unsigned(time(0)));
	ran1 = (int)(rand()%8+2);
	ran2 = (int)(rand()%8+2);
	while(ran1 == ran2)
		ran2 = (int)(rand()%8+2);
	play.inputPrincess(ran1);
	play.inputDemon(ran2); //generate a random number from 2-9

	play.changeTag(1);
	cout << "Welcome to the lobby. There are 3 exits as: east, west and up." << endl;
	cout << "Enter your command:" << endl;
	while(1)
	{
		play.getCommand();
		t = play.goToNext();
		while(1)
		{
			if(t)
				break;
			else	
				cout << "The room doesn't exit! Please input again" << endl;
			play.getCommand();
			t = play.goToNext();
		}
		if(t == 1 && meet)
		{
			cout << "congratulation! You win the game." << endl;
			break;
		}
		play.changeTag(t);
		w = play.whatHappened(meet);
		if(w == -1)
			break;
		else if(w == 1)
			meet = 1;
	}
	return 0;
}
