#ifndef __xxy__Media__
#define __xxy__Media__

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Media{
protected:
	string title;
	int kind;
public:
	Media(string& tit, int k);
	~Media();
	int getKind(void){return kind;}
	string getTitle(void){return title;}
	void print_title(void){cout << title;}
	virtual void print(void){cout<<"media"<<endl;}
};

#endif /* defined(__xxy__Media_) */
