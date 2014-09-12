#include<iostream>
#include<vector>
using namespace std;
class A{
private :
	int kind;
public :
	A(){kind = 0;}
	A(int k){kind = k;}
	~A(){}
	int getKind(){return kind;}
	void setKind(int k){ kind = k;}
	virtual void print(){
		cout<<"This is A."<<endl;
	}
};
class B:public A{
public:
	B():A(1){};
	~B(){}
	void print()
	{
		cout<<"This is B."<<endl;
	}
	void printB()
	{
		cout<<"BBBBBBBBBBBB"<<endl;
	}
};
class C:public A{
public:
	C()
	{
		this->setKind(2);
	}
	~C(){}
	void print()
	{
		cout<<"This is C."<<endl;
	}
	void printC()
	{
		cout<<"CCCCCCCCCCCC"<<endl;
	}
};
int main()
{
	
	
	
	A* a = new A();
	B* b = new B();
	C* c = new C();
	vector<A*> v_A;
	v_A.push_back(a);
	v_A.push_back(b);
	v_A.push_back(c);

	vector<A*>::size_type i;
	for (i = 0;i < v_A.size();i++)
	{
		v_A[i]->print();

		if (v_A[i]->getKind() == 1)
			((B*)v_A[i])->printB();
		if (v_A[i]->getKind() == 2)
			((C*)v_A[i])->printC();
		cout<<endl;
	}

	delete a;
	delete b;
	delete c;
	
}