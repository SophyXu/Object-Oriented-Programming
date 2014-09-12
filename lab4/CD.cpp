#include "CD.h"

CD::CD(string& tit, string& art, int num) : Media(tit, 1), artist(art), track_num(num)
{}
void CD::print(void)
{
	Media::print_title();
	cout << '\t' << '\t' << artist << '\t' << '\t' << track_num << endl;
}