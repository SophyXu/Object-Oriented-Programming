#include"diary.h"

void Diary::PdAdd()
{
	string str;
	getline(cin,str);
	while (str!=".")
	{
		text.push_back(str);
		getline(cin,str);
	}
}
void Diary::SetDate(string D)
{
	date = D;
}
void Diary::Reset()
{
	text.clear();
}

string Diary::GetDate()
{
	return date;
}

VStringSize Diary::Size()
{
	return text.size();
}
string Diary::GetText(VStringSize i)
{
	return text[i];
}
void Diary::AddLine(string Line)
{
	text.push_back(Line);
}