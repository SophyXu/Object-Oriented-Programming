#ifndef __xxy__Game__
#define __xxy__Game__

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "Rome.h"
using namespace std;

class Game{
private:
	int now; // the current room's tag
	string command; 
	vector<Room*> rooms;
public:
	Game(){rooms.push_back(new Room());}
	~Game(){}
	void addRoom(Room* r); 
    void inputPrincess(int f); // input princess in room f
    void inputDemon(int f); // input demon in room f
	void getCommand(void); // read in a new command
	int goToNext(void); // if succeed, return the next room's tag, return 0 if not
	void changeTag(int t); // enter the room t
	int whatHappened(int meet); //print info of the next room and return 0, -1, 1 to represent the state
};

#endif /* defined(__xxy__Game_) */