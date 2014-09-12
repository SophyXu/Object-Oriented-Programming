#include "Room.h"

Room::Room(string name, int t, int a, int b, int c, int d, int e, int f, int s)
{
	this->name = name;
	tag = t;
	east = a;
	west = b;
	south = c;
	north = d;
	up = e;
	down = f;
	state = s;
}
int Room::getNum(void)
{
	int count = 0;
	if(isEast())
		count++;
	if(isWest())
		count++;
	if(isSouth())
		count++;
	if(isNorth())
		count++;
	if(isUp())
		count++;
	if(isDown())
		count++;
	return count;
}
void Room::princess(void)
{
	state = 1;
}
void Room::demon(void)
{
	state = -1;
}
void Room::printInfo(void)
{
	int i, flag = 1;
	//´ý½â¾ö
	cout << "Welcome to the "<< name << " " << tag << ". There are " << getNum() << " exits as:";
		if(isEast()){flag = 0; cout << " east";}
		if(isWest()){
			if(flag){
				flag = 0;
				cout << " west";
			}
			else
				cout << ", west";
		}
		if(isSouth()){
			if(flag){
				flag = 0;
				cout << " south";
			}
			else
				cout << ", south";
		}
		if(isNorth()){
			if(flag){
				flag = 0;
				cout << " north";
			}
			else	
				cout << ", north";
		}
		if(isUp()){
			if(flag){
				flag = 0;
				cout << " up";
			}
			cout << ", up";
		}
		if(isDown()){
			if(flag){
				flag = 0;
				cout << " down";
			}
			cout << ", down";
		}
	cout << "." << endl;
	cout << "Enter your command:" << endl;
}