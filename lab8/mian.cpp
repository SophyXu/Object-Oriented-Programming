#include "Fraction.h"

int main()
{
	Fraction A,B,C;
	cin>>A>>B;
	cout<<"A = "<<A<<"\tB = "<<B<<endl;
	cout<<"A + B = "<<(A + B)<<" = "<<(double)(A + B)<<endl;
	cout<<"A - B = "<<(A - B)<<" = "<<(double)(A - B)<<endl;
	cout<<"A * B = "<<(A * B)<<" = "<<(double)(A * B)<<endl;
	cout<<"A / B = "<<(A / B)<<" = "<<(double)(A / B)<<endl;
	cout<<"Is A < B ? "<<(A < B)<<endl;
	cout<<"Is A > B ? "<<(A > B)<<endl;
	cout<<"Is A<= B ? "<<(A <= B)<<endl;
	cout<<"Is A>= B ? "<<(A >= B)<<endl;
	cout<<"Is A== B ? "<<(A == B)<<endl;
	cout<<"Is A!= B ? "<<(A != B)<<endl;
	cout<<"A toString: "<<A.toString()<<endl;
	cout<<"END"<<endl;
	return 0;
}