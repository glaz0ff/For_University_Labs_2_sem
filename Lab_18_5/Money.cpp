#include "Money.h"
#include <iostream>
using namespace std;

Money::Money(void)
{
	this->rub = 0;
	this->kop = 0;
}
Money::~Money(void)
{

}
Money::Money(int F, int S)
{
	this->rub = F;
	this->kop = S;
}
Money::Money(const Money& pair)
{
	this->rub = pair.rub;
	this->kop = pair.kop;
}
void Money::set_rub(int F)
{
	this->rub = F;
}
void Money::set_kop(int S)
{
	this->kop = S;
}

float Money::operator / (const Money& c)
{
	int temp1 = this->rub * 100 + this->kop,
		temp2 = c.rub * 100 + c.kop;
	float temp3 = temp1 / temp2;
	return temp3;
}

Money& Money::operator - (const Money& c)
{
	int temp1 = this->rub * 100 + this->kop,
		temp2 = c.rub * 100 + c.kop;
	int temp3 = temp1 - temp2;
	this->rub = temp3 / 100;
	this->kop = temp3 % 100;
	return *this;
}

Money& Money::operator + (const Money& c)
{
	int temp1 = this->rub * 100 + this->kop,
		temp2 = c.rub * 100 + c.kop;
	int temp3 = temp1 + temp2;
	this->rub = temp3 / 100;
	this->kop = temp3 % 100;
	return *this;
}


Money& Money::operator=(const Money& k)
{
	if (&k == this)return*this;
	this->rub = k.rub;
	this->kop = k.kop;
	return *this;
}
istream& operator >> (istream& in, Money& c)
{
	int n;
	cout << "Рубли: "; in >> c.rub;
	cout << "Копейки: "; in >> c.kop;
	if (c.kop > 100)
	{
		n = c.kop / 100;
		c.rub = c.rub + n;
		c.kop = c.kop % 100;
	}
	return in;

}
ostream& operator << (ostream& out, const Money& c)
{
	out << "Рубли: " << c.rub;
	cout << endl;
	out << "Копейки: " << c.kop;
	cout << endl;
	out << endl;
	return out;

}