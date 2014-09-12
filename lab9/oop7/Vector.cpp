#include"Vector.h"
void IndexOutofBounds::printErr()
{
       cerr<<"Index "<<Index<<" is out of range!\n";
}
IndexOutofBounds::IndexOutofBounds(int i):Index(i)
{}
IndexOutofBounds::~IndexOutofBounds(){}