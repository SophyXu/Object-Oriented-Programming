#include "Type_three.h"

Type_three::Type_three(int t, int w)
{
	north = 0;
	south = 0;
	east = 0;
	west = w;
	up = 0;
	down = 0;
	tag = t;
}
void Type_three::printInfo(void)
{
	cout << "Welcome to room No."<< getTag() << ". There are 1 exits as: east." << endl;
	cout << "Enter your command:" << endl;
}