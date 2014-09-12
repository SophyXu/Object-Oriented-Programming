#include <iostream>
#include <string>
#include <vector>
#include "Media.h"
#include "CD.h"
#include "DVD.h"
using namespace std;

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
