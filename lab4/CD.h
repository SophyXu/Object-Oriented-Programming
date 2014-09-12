#ifndef __xxy__CD__
#define __xxy__CD__

#include <iostream>
#include <string>
#include <vector>
#include "Media.h"
using namespace std;

class CD : public Media{
private:
	string artist;
	int track_num;
public:
	CD(string& tit, string& art, int num);
	~CD(){}
	void print(void);
};

#endif /* defined(__xxy__CD_) */
