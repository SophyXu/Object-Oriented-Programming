#include "DVD.h"

DVD::DVD(string& tit, string& dir, int len) : Media(tit, 2), director(dir), film_len(len)
{}
void DVD::print(void)
{
	Media::print_title();
	cout << '\t' << '\t' << director << '\t' << '\t' << film_len << endl;	
}