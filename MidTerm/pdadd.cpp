#include"diary.h"
int compstr(string str1,string str2)
{
	return str1.compare(str2)==1;
}
int main(int garc,char *garv[])
{
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

	date = garv[1];
	diary.Reset();
	diary.SetDate(date);
	getline(cin,str);
	while (str!=".")
	{
		diary.AddLine(str);
		getline(cin,str);
	}
	vector<Diary>::size_type i,Size,ii;
	Size=my_diary.size();
	
	for (i=0;i<Size;i++)
		if (my_diary[i].GetDate()==date) break;
	if (i==Size)
	{
		my_diary.push_back(diary);
		for (i=0;i<Size;i++)
			if(compstr(my_diary[i].GetDate(),diary.GetDate()))	break;
		for (ii=Size;ii>i;ii--)
			my_diary[ii]=my_diary[ii-1];
		my_diary[i]=diary;
	}
	else
		my_diary[i] = diary;
	
	ofstream f_out(fpath);
	for (i=0;i<my_diary.size();i++)
	{
		f_out<<my_diary[i].GetDate()<<endl;
		vector<string>::size_type j;
		for (j=0;j<my_diary[i].Size();j++)
			f_out<<my_diary[i].GetText(j)<<endl;
		f_out<<"."<<endl;
	}
	f_out.close();
	
	return 0;
}