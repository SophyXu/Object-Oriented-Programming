#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include "Room.h"
#include "Type_one.h"
#include "Type_two.h"
#include "Type_three.h"
#include "Type_four.h"
#include "Type_five.h"
#include "Type_six.h"
#include "Game.h"
using namespace std;

int main()
{
	int meet = 0, t, ww, ran1, ran2, i, j, n, s, w, e, u, d;
	Room *p;
	Type_one* temp = new Type_one(0, 0);
	Game play;	
	//first colume of map.txt is the type of the room, and follow the tags it conntects to
	string file_name="map.txt";
	ifstream fin(file_name.c_str());
	if (fin.fail()) {
		cout<<"no find Map";
		return 0;
	}
	int fs;
	for(i=1;i<=9;i++)
	{
		fin>>fs;
		switch(fs){
			case 1:	fin>>s;
						p = new Type_one(i, s);  break;
			case 2:   fin>>n; fin>>s; fin>>e; fin>>u;
						p = new Type_two(i, n, s, e, u);  break;
			case 3:	fin>>w;
						p = new Type_three(i, w); break;
			case 4:	fin>>n; fin>>s;
						p = new Type_four(i, n, s); break;
			case 5:	fin>>n;
						p = new Type_five(i, n); break;
			case 6:	fin>>s; fin>>e; fin>>d;
						p = new Type_six(i, s, e, d); break;
			default: p = NULL;
		}
		if (p) play.addRoom(p);
	}
	fin.close();  
	
	srand(unsigned(time(0)));
	ran1 = (int)(rand()%8+2);
	ran2 = (int)(rand()%8+2);
	while(ran1 == ran2)
		ran2 = (int)(rand()%8+2);
	play.inputPrincess(ran1);
	play.inputDemon(ran2); //generate a random number from 2-9

	play.changeTag(1);
	cout << "Welcome to the lobby. There are 1 exits as: south." << endl;
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
		ww = play.whatHappened(meet);
		if(ww == -1)
			break;
		else if(ww == 1)
			meet = 1;
	}
	return 0;
}
