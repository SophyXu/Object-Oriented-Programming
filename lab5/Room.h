#ifndef __xxy__Room__
#define __xxy__Room__

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Room{
protected:
	int east; // 0->doesn't exist ; num-> tag for the next room
	int west;
	int south;
	int north;
	int up;
	int down;
	int state; // 0->nothing ; 1-> princess ; -1->demon
	int tag; // tag for vector
public:
	Room(){}
	virtual ~Room();

	void princess(void){state = 1;}
	void demon(void){state = -1;}
	virtual int East(void) {return 0;} // return the tag of the east room
	virtual int West(void) {return 0;}
	virtual int South(void) {return 0;}
	virtual int North(void) {return 0;}
	virtual int Up(void) {return 0;}
	virtual int Down(void) {return 0;}
	virtual int getState(void){return state;} // what's in this room
	virtual int getTag(void){return tag;} // return the room tag
	virtual void printInfo(void) {} // print the info of this room
};

#endif /* defined(__xxy__Room__) */