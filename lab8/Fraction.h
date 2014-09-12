#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Fraction
{
private:
	int n,m;
public:
	Fraction();
	Fraction(const Fraction &);
	Fraction(int,int);
	~Fraction(void);
	int GCD(int ,int);
	void Set();
	const Fraction operator + (const Fraction &);
	const Fraction operator - (const Fraction &);
	const Fraction operator * (const Fraction &);
	const Fraction operator / (const Fraction &);
	bool operator < (const Fraction &)const;
	bool operator > (const Fraction &)const;
	bool operator <= (const Fraction &)const;
	bool operator >= (const Fraction &)const;
	bool operator == (const Fraction &)const;
	bool operator != (const Fraction &)const;
	operator double() const;
	string toString();
	friend istream &operator>>(istream &in, Fraction &rv);
    friend ostream &operator<<(ostream &out, const Fraction &rv);
	void print();
};
