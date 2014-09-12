#include "Fraction.h"
Fraction::Fraction(int N,int M):n(N),m(M)
{}

Fraction::Fraction()
{}
Fraction::Fraction(const Fraction & o):n(o.n),m(o.m)
{}
Fraction::~Fraction(void)
{}

int Fraction::GCD(int n,int m)
{
	int temp;
	if (m<n)
	{
		temp=m;
		m=n;
		n=temp;
	}
	if (m%n==0) return n;
	else
		return GCD(m%n,n);
}
void Fraction::Set()
{
	cin>>n>>m;
}
void Fraction::print()
{
	cout<<n<<"/"<<m<<endl;
}

const Fraction Fraction::operator + (const Fraction &that)
{
	int mm,nn,gcd;
	mm = this->m * that.m;
	nn = this->n * that.m + that.n * this->m;
	if (nn>0) gcd = GCD(nn,mm);
	if (nn<0) gcd = GCD(-nn,mm);
	if (nn==0) gcd = 1;
	mm/=gcd;
	nn/=gcd;
	return Fraction(nn,mm);

}
const Fraction Fraction::operator - (const Fraction &that)
{
	int mm,nn,gcd;
	mm = this->m * that.m;
	nn = this->n * that.m - that.n * this->m;
	if (nn>0) gcd = GCD(nn,mm);
	if (nn<0) gcd = GCD(-nn,mm);
	if (nn==0) gcd = 1;
	mm/=gcd;
	nn/=gcd;
	return Fraction(nn,mm);

}
const Fraction Fraction::operator * (const Fraction &that)
{
	int mm,nn,gcd;
	mm = this->m * that.m;
	nn = this->n * that.n;
	if (nn>0) gcd = GCD(nn,mm);
	if (nn<0) gcd = GCD(-nn,mm);
	if (nn==0) gcd = 1;
	mm/=gcd;
	nn/=gcd;
	return Fraction(nn,mm);

}
const Fraction Fraction::operator / (const Fraction &that)
{
	int mm,nn,gcd;
	mm = this->m * that.n;
	nn = this->n * that.m;
	if (nn>0) gcd = GCD(nn,mm);
	if (nn<0) gcd = GCD(-nn,mm);
	if (nn==0) gcd = 1;
	mm/=gcd;
	nn/=gcd;
	return Fraction(nn,mm);

}
bool Fraction::operator<(const Fraction &that)const
{
	int result;
	result = this->n * that.m - that.n * this->m;
	if (result<0) return 1;
	else return 0;
}
bool Fraction::operator>=(const Fraction &that)const
{
	return !(*this < that);
}
bool Fraction::operator> (const Fraction &that)const
{
	return (that<*this);
}
bool Fraction::operator<=(const Fraction &that)const
{
	return !(*this>that);
}
bool Fraction::operator==(const Fraction &that)const
{
	int result;
	result = this->n * that.m - that.n * this->m;
	if (result == 0) return 1;
	else return 0;

}
bool Fraction::operator!=(const Fraction &that)const
{
	return !(*this == that);
}
istream &operator>>(istream &in, Fraction &rv)
{
	in>>rv.n;
	char ch;
	in>>ch;
	in>>rv.m;
	return in;
}
ostream &operator<<(ostream &out, const Fraction &rv)
{
	if (rv.n==0||rv.m==1)
		out<<rv.n;
	else
		out<<rv.n<<"/"<<rv.m;

	return out;
}
Fraction::operator double()const
{
	return (1.0*n/m);
}
string Fraction::toString()
{
	stringstream ss1,ss2;
	string str1="",str2="";
	ss1<<n;
	ss1>>str1;
	ss2<<m;
	ss2>>str2;
	str1=str1+"/"+str2;
	return str1;
}