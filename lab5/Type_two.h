#ifndef __xxy__Type_two__
#define __xxy__Type_two__

#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
using namespace std;

class Type_two : public Room{
public:
	Type_two(int t, int n, int s, int e, int u);
	int North(void){return north;}
	int South(void){return south;}
	int East(void){return east;}
	int Up(void){return up;}
	void printInfo(void);
};

#endif /* defined(__xxy__Type_two_) */
