#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Media{
protected:
	string title;
	int kind;
public:
	Media(string& tit, int k);
	~Media();
	int getKind(void){return kind;}
	string getTitle(void){return title;}
	void print_title(void){cout << title;}
	virtual void print(void){cout<<"media"<<endl;}
};
class CD : public Media{
private:
	string artist;
	int track_num;
public:
	CD(string& tit, string& art, int num);
	void print(void);
};

class DVD : public Media{
private:
	string director;
	int film_len;
public:
	DVD(string& tit, string& dir, int len);
	void print(void);	
};

Media::Media(string& tit, int k) : title(tit), kind(k)
{}
Media::~Media(){}

CD::CD(string& tit, string& art, int num) : Media(tit, 1), artist(art), track_num(num)
{}
void CD::print(void)
{
	Media::print_title();
	cout << '\t' << '\t' << artist << '\t' << '\t' << track_num << endl;
}


DVD::DVD(string& tit, string& dir, int len) : Media(tit, 2), director(dir), film_len(len)
{}
void DVD::print(void)
{
	Media::print_title();
	cout << '\t' << '\t' << director << '\t' << '\t' << film_len << endl;	
}

int main()
{
	int i;
	string title, name, kind, search;
	string instruction;
	int num;
	vector<Media*> medium;
	cout << "input instrction : add, retrieve, print and end" << endl;
	while(1)
	{
		cin >> instruction;
		if(instruction == "end")
			break;
		if(instruction == "add")
		{
			cout << "input the media kind:CD and DVD" << endl;
			cin >> kind;
			if(kind == "CD")
			{
				cout << "input title, artist and number of tracks" << endl;
				cin >> title >> name >> num;
				CD* c = new CD(title, name, num);
				medium.push_back(c);
			}
			if(kind == "DVD")
			{
				cout << "input title, director and length of the film" << endl;
				cin >> title >> name >> num;
				DVD* d = new DVD(title, name, num);
				medium.push_back(d);
			}

		}
		if(instruction == "retrieve")
		{
			cout << "input title:" << endl;
			cin >> search;
			cout << "******************************" << endl;
			cout << "CD:" << endl;
			cout << "title" << '\t' << '\t' << "artist" << '\t' << '\t' << "number of tracks" << endl;
			for(i=0;i<medium.size();i++)
			{
				if(medium[i]->getTitle() == search && medium[i]->getKind() == 1)
					medium[i]->print();
			}
			cout << "******************************" << endl;
			cout << "DVD:" << endl;
			cout << "title" << '\t' << '\t' << "director" << '\t' << '\t' << "length of the film" << endl;
			for(i=0;i<medium.size();i++)
			{
				if(medium[i]->getTitle() == search && medium[i]->getKind() == 2)
					medium[i]->print();
			}
			cout << "******************************" << endl;
		}
		if(instruction == "print")
		{
			cout << "******************************" << endl;
			cout << "CD:" << endl;
			cout << "title" << '\t' << '\t' << "artist" << '\t' << '\t' << "number of tracks" << endl;
			for(i=0;i<medium.size();i++)
			{
				if(medium[i]->getKind() == 1)
					medium[i]->print();
			}
			cout << "******************************" << endl;
			cout << "DVD:" << endl;
			cout << "title" << '\t' << '\t' << "director" << '\t' << '\t' << "length of the film" << endl;
			for(i=0;i<medium.size();i++)
			{
				if(medium[i]->getKind() == 2)
					medium[i]->print();
			}
			cout << "******************************" << endl;
		}
		cout << "input instrction : add, retrieve, print and end" << endl;
	}
	return 0;
}
