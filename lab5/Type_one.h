#ifndef __xxy__Type_one__
#define __xxy__Type_one__

#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
using namespace std;

class Type_one : public Room{
public:
	Type_one(int t, int s);
	int South(void){return south;}	
	void printInfo(void);
};

#endif /* defined(__xxy__Type_one_) */
