#include<iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
using namespace std;
typedef vector<string>::size_type VStringSize;
#define fpath "diary.txt"

class Diary
{
private:
	string date;
	vector<string> text;
public:
	void Reset();
	void PdAdd();
	void SetDate(string);
	void AddLine(string);
	string GetText(VStringSize);
	string GetDate();
	VStringSize Size();

};
