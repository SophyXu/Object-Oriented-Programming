#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Room{
protected:
	int east; // 0->doesn't exist ; num-> tag for the next room
	int west;
	int south;
	int north;
	int up;
	int down;
	int state; // 0->nothing ; 1-> princess ; -1->demon
	int tag; // tag for vector
public:
	Room(){}
	virtual ~Room();

	void princess(void){state = 1;}
	void demon(void){state = -1;}
	virtual int East(void) {return 0;} // return the tag of the east room
	virtual int West(void) {return 0;}
	virtual int South(void) {return 0;}
	virtual int North(void) {return 0;}
	virtual int Up(void) {return 0;}
	virtual int Down(void) {return 0;}
	virtual int getState(void){return state;} // what's in this room
	virtual int getTag(void){return tag;} // return the room tag
	virtual void printInfo(void) {} // print the info of this room
};

Room::~Room(){
	
}

class Type_one : public Room{
public:
	Type_one(int t, int s);
	int South(void){return south;}	
	void printInfo(void);
};

class Type_two : public Room{
public:
	Type_two(int t, int n, int s, int e, int u);
	int North(void){return north;}
	int South(void){return south;}
	int East(void){return east;}
	int Up(void){return up;}
	void printInfo(void);
};

class Type_three : public Room{
public:
	Type_three(int t, int w);
	int West(void){return west;}
	void printInfo(void);
};

class Type_four : public Room{
public:
	Type_four(int t, int n, int s);
	int North(void){return north;}
	int South(void){return south;}
	void printInfo(void);
};

class Type_five : public Room{
public:
	Type_five(int t, int n);
	int North(void){return north;}
	void printInfo(void);
};

class Type_six : public Room{
public:
	Type_six(int t, int s, int e, int d);
	int North(void){return north;}
	int South(void){return south;}
	int East(void){return east;}
	int Down(void){return down;}
	void printInfo(void);
};

class Game{
private:
	int now; // the current room's tag
	string command; 
	vector<Room*> rooms;
public:
	Game(){rooms.push_back(new Room());}
	~Game(){}
	void addRoom(Room* r); 
    void inputPrincess(int f); // input princess in room f
    void inputDemon(int f); // input demon in room f
	void getCommand(void); // read in a new command
	int goToNext(void); // if succeed, return the next room's tag, return 0 if not
	void changeTag(int t); // enter the room t
	int whatHappened(int meet); //print info of the next room and return 0, -1, 1 to represent the state
};

Type_one::Type_one(int t, int s)
{
	north = 0;
	south = s;
	east = 0;
	west = 0;
	up = 0;
	down = 0;
	tag = t;
	state = 0;
}
void Type_one::printInfo(void)
{
	cout << "Welcome to room No."<< getTag() << ". There are 1 exits as: south." << endl;
	cout << "Enter your command:" << endl;
}

Type_two::Type_two(int t, int n, int s, int e, int u)
{
	north = n;
	south = s;
	east = e;
	west = 0;
	up = u;
	down = 0;
	tag = t;
	state = 0;
}
void Type_two::printInfo(void)
{
	cout << "Welcome to room No."<< getTag() << ". There are 4 exits as: north, south, east and up." << endl;
	cout << "Enter your command:" << endl;
}

Type_three::Type_three(int t, int w)
{
	north = 0;
	south = 0;
	east = 0;
	west = w;
	up = 0;
	down = 0;
	tag = t;
	state = 0;
}
void Type_three::printInfo(void)
{
	cout << "Welcome to room No."<< getTag() << ". There are 1 exits as: west." << endl;
	cout << "Enter your command:" << endl;
}

Type_four::Type_four(int t, int n, int s)
{
	north = n;
	south = s;
	east = 0;
	west = 0;
	up = 0;
	down = 0;
	tag = t;
	state = 0;
}
void Type_four::printInfo(void)
{
	cout << "Welcome to room No."<< getTag() << ". There are 2 exits as: north and south." << endl;
	cout << "Enter your command:" << endl;
}

Type_five::Type_five(int t, int n)
{
	north = n;
	south = 0;
	east = 0;
	west = 0;
	up = 0;
	down = 0;
	tag = t;
	state = 0;
}
void Type_five::printInfo(void)
{
	cout << "Welcome to room No."<< getTag() << ". There are 1 exits as: north." << endl;
	cout << "Enter your command:" << endl;
}

Type_six::Type_six(int t, int s, int e, int d)
{
	north = 0;
	south = s;
	east = e;
	west = 0;
	up = 0;
	down = d;
	tag = t;
	state = 0;
}
void Type_six::printInfo(void)
{
	cout << "Welcome to room No."<< getTag() << ". There are 3 exits as: north, east and down." << endl;
	cout << "Enter your command:" << endl;
}

void Game::addRoom(Room* r)
{
	rooms.push_back(r);	
}
void Game::inputPrincess(int f)
{
	rooms[f]->princess();
}
void Game::inputDemon(int f)
{
	rooms[f]->demon();
}
void Game::getCommand(void)
{
	string go, direction;
	cin >> go >> this->command;
}
int Game::goToNext(void)
{
	if(command == "east")
		return rooms[now]->East();
	else if(command == "west")
		return rooms[now]->West();
	else if(command == "south")
		return rooms[now]->South();
	else if(command == "north")
		return rooms[now]->North();
	else if(command == "up")
		return rooms[now]->Up();
	else if(command == "down")
		return rooms[now]->Down();
	else{
		cout << "wrong command!" << endl;
		return 0;
	}
}
void Game::changeTag(int t)
{
	now = t;
}
int Game::whatHappened(int meet)
{
	if(!rooms[now]->getState()){
		rooms[now]->printInfo();
		return 0;
	}
	else if(rooms[now]->getState()==1){
		if(!meet){
		cout << "congratulation! You find the princess!" << endl;
		cout << "The process is going to leave with the you" << endl;
		}
		rooms[now]->printInfo();
		return 1;		 
	}
	else if(rooms[now]->getState()==-1){
		cout << "Oops! There is a monster! " << endl;
		cout << "GAME OVER" << endl;
		return -1;
	}

}

int main()
{
	int meet = 0, t, ww, ran1, ran2, i, j, n, s, w, e, u, d;
	Room *p;
	Type_one* temp = new Type_one(0, 0);
	Game play;	
	string file_name="map.txt";
	ifstream fin(file_name.c_str());
	if (fin.fail()) {
		cout<<"no find Map";
		return 0;
	}
	int fs;
	for(i=1;i<=9;i++)
	{
		fin>>fs;
		switch(fs){
			case 1:	fin>>s;
						p = new Type_one(i, s);  break;
			case 2:   fin>>n; fin>>s; fin>>e; fin>>u;
						p = new Type_two(i, n, s, e, u);  break;
			case 3:	fin>>w;
						p = new Type_three(i, w); break;
			case 4:	fin>>n; fin>>s;
						p = new Type_four(i, n, s); break;
			case 5:	fin>>n;
						p = new Type_five(i, n); break;
			case 6:	fin>>s; fin>>e; fin>>d;
						p = new Type_six(i, s, e, d); break;
			default: p = NULL;
		}
		if (p) play.addRoom(p);
	}
	fin.close();  
	
	srand(unsigned(time(0)));
	ran1 = (int)(rand()%8+2);
	ran2 = (int)(rand()%8+2);
	while(ran1 == ran2)
		ran2 = (int)(rand()%8+2);
	play.inputPrincess(ran1);
	play.inputDemon(ran2); //generate a random number from 2-9

	play.changeTag(1);
	cout << "Welcome to the lobby. There are 1 exits as: south." << endl;
	cout << "Enter your command:" << endl;
	
	while(1)
	{
		
		play.getCommand();
		t = play.goToNext();
		while(1)
		{
			if(t)
				break;
			else	
				cout << "The room doesn't exit! Please input again" << endl;
			play.getCommand();
			t = play.goToNext();
		}
		if(t == 1 && meet)
		{
			cout << "congratulation! You win the game." << endl;
			break;
		}
		play.changeTag(t);
		ww = play.whatHappened(meet);
		if(ww == -1)
			break;
		else if(ww == 1)
			meet = 1;
	}
	return 0;
}
