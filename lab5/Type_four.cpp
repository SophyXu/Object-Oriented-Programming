#include "Type_four.h"

Type_four::Type_four(int t, int n, int s)
{
	north = n;
	south = s;
	east = 0;
	west = 0;
	up = 0;
	down = 0;
	tag = t;
}
void Type_four::printInfo(void)
{
	cout << "Welcome to room No."<< getTag() << ". There are 2 exits as: north and south." << endl;
	cout << "Enter your command:" << endl;
}