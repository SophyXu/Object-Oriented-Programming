#include "Type_two.h"

Type_two::Type_two(int t, int n, int s, int e, int u)
{
	north = n;
	south = s;
	east = e;
	west = 0;
	up = u;
	down = 0;
	tag = t;
}
void Type_two::printInfo(void)
{
	cout << "Welcome to room No."<< getTag() << ". There are 4 exits as: north, south, east and up." << endl;
	cout << "Enter your command:" << endl;
}