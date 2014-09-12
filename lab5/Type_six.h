#ifndef __xxy__Type_six__
#define __xxy__Type_six__

#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
using namespace std;

class Type_six : public Room{
public:
	Type_six(int t, int s, int e, int d);
	int North(void){return north;}
	int South(void){return south;}
	int East(void){return east;}
	int Down(void){return down;}
	void printInfo(void);
};

#endif /* defined(__xxy__Type_six_) */
