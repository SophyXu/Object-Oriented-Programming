#ifndef __xxy__Type_four__
#define __xxy__Type_four__

#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
using namespace std;

class Type_four : public Room{
public:
	Type_four(int t, int n, int s);
	int North(void){return north;}
	int South(void){return south;}
	void printInfo(void);
};

#endif /* defined(__xxy__Type_four_) */
