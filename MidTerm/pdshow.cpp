#include "diary.h"
int main(int argc,char *argv[])
{
	vector<Diary> my_diary;
	string str;
	Diary diary;
	Diary *p;
	string date;
	ifstream f_in(fpath);
	while (!f_in.eof())
	{
		getline(f_in,date);
		diary.SetDate(date);
		diary.Reset();
		string str;
		getline(f_in,str);
		while (str!=".")
		{
			diary.AddLine(str);
			getline(f_in,str);
		}
		my_diary.push_back(diary);
	}
	f_in.close();
	date=argv[1];
	vector<Diary>::size_type i,Size;
	Size=my_diary.size();
	for (i=0;i<Size;i++)
		if (my_diary[i].GetDate()==date) break;
	if (i==Size)
		cout<<"There is not such a diary which date is "<<date<<"."<<endl;
	else
	{
		cout<<my_diary[i].GetDate()<<endl;
		vector<string>::size_type j;
		for (j=0;j<my_diary[i].Size();j++)
			cout<<my_diary[i].GetText(j)<<endl;
		cout<<"."<<endl;
	}

	return 0;
}