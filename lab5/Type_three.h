#ifndef __xxy__Type_three__
#define __xxy__Type_three__

#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
using namespace std;

class Type_three : public Room{
public:
	Type_three(int t, int w);
	int West(void){return west;}
	void printInfo(void);
};

#endif /* defined(__xxy__Type_three_) */
