#ifndef __xxy__DVD__
#define __xxy__DVD__

#include <iostream>
#include <string>
#include <vector>
#include "Media.h"
using namespace std;

class DVD : public Media{
private:
	string director;
	int film_len;
public:
	DVD(string& tit, string& dir, int len);
	~DVD(){}
	void print(void);	
};

#endif /* defined(__xxy__DVD_) */
