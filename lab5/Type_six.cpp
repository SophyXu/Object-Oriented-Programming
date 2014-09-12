#include "Type_six.h"

Type_six::Type_six(int t, int s, int e, int d)
{
	north = 0;
	south = s;
	east = e;
	west = 0;
	up = 0;
	down = d;
	tag = t;
}
void Type_six::printInfo(void)
{
	cout << "Welcome to room No."<< getTag() << ". There are 3 exits as: north, east and down." << endl;
	cout << "Enter your command:" << endl;
}