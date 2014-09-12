#include "Type_one.h"

Type_one::Type_one(int t, int s)
{
	north = 0;
	south = s;
	east = 0;
	west = 0;
	up = 0;
	down = 0;
	tag = t;
}
void Type_one::printInfo(void)
{
	cout << "Welcome to room No."<< getTag() << ". There are 1 exits as: south." << endl;
	cout << "Enter your command:" << endl;
}