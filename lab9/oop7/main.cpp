#include <iostream>
#include "Vector.h"
using namespace std;
int main()
{
   	Vector<int> A;
	Vector<int> B(5);
	cout<<"******* The size of A and B *******\n";
	cout<<"A.size() = "<<A.size()<<endl;
	cout<<"B.size() = "<<B.size()<<endl;
	cout<<endl;
	A.inflate(2);
	cout<<"*******  After inflate(2)  ********\nA.size() = "<<A.size()<<endl;
	cout<<endl;
	A[0]=10;	A[1]=100;
	Vector<int> C(A);
	cout<<"*******  C is copy from A  *********"<<endl;
	cout<<"A.size() = "<<A.size()<<"\tA[0] = "<<A[0]<<"\tA[1] = "<<A[1]<<endl;
	cout<<"C.size() = "<<C.size()<<"\tC[0] = "<<C[0]<<"\tC[1] = "<<C[1]<<endl;
	cout<<endl;
	cout<<"*******  Try giving A[10] a value *******\n";
	try{
		A[10]=10;
	}catch(IndexOutofBounds &Err)
	{
		Err.printErr();
	}
	cout<<endl;
	return 0;
}
