#ifndef __xxy__Type_five__
#define __xxy__Type_five__

#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
using namespace std;

class Type_five : public Room{
public:
	Type_five(int t, int n);
	int North(void){return north;}
	void printInfo(void);
};

#endif /* defined(__xxy__Type_three_) */
