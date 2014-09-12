#include "Type_five.h"

Type_five::Type_five(int t, int n)
{
	north = n;
	south = 0;
	east = 0;
	west = 0;
	up = 0;
	down = 0;
	tag = t;
}
void Type_five::printInfo(void)
{
	cout << "Welcome to room No."<< getTag() << ". There are 1 exits as: north." << endl;
	cout << "Enter your command:" << endl;
}