#include"diary.h"
#include<stdlib.h>
int between(string str,string upper,string low)
{
	if (str.compare(upper)<=0&&str.compare(low)>=0)	
		return 1;
	else	
		return 0;
}

int main(int argc,char *argv[])
{
	/*int argc=3;
	char *argv[3]={"","2013/01/01","2013/05/11"};*/
	vector<Diary> my_diary;
	string str;
	Diary diary;
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

	vector<Diary>::size_type i,Size;
	Size=my_diary.size();
	VStringSize j;
	if (argc==3)
	{
		string dateUpper,dateLow;
		dateUpper=argv[2];
		dateLow=argv[1];

		for (i=0;i<Size;i++)
			if (between(my_diary[i].GetDate(),dateUpper,dateLow))
			{
				cout<<my_diary[i].GetDate()<<endl;
				cout<<my_diary[i].GetText(0)<<endl;
	
			}
	}
	else
		for (i=0;i<my_diary.size();i++)
		{
			cout<<my_diary[i].GetDate()<<endl;
			vector<string>::size_type j;
			cout<<my_diary[i].GetText(0)<<endl;

		}
	
	return 0;
}