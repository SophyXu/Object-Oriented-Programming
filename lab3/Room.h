#ifndef __xxy__Room__
#define __xxy__Room__

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Room{
private:
	int east; // 0->doesn't exist ; num-> tag for the next room
	int west;
	int south;
	int north;
	int up;
	int down;
	int state; // 0->nothing ; 1-> princess ; -1->demon
	int tag; // tag for vector
	string name;
public:
	Room(string name, int t, int a, int b, int c, int d, int e, int f, int s);
	~Room(){}
	int getNum(void); // how many
	void princess(void);
	void demon(void);
	int isEast(void){return east;} // return the tag of the east room
	int isWest(void){return west;}
	int isSouth(void){return south;}
	int isNorth(void){return north;}
	int isUp(void){return up;}
	int isDown(void){return down;}
	int getState(void){return state;} // what's in this room
	string getName(void){return name;} // return the name
	int getTag(void){return tag;} // return the room tag
	void printInfo(void); // print the info of this room
};

#endif /* defined(__xxy__Room__) */
