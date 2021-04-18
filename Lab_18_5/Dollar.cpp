#include "Dollar.h"
#include "Money.h"
#include <iostream>
using namespace std;

Dollar::Dollar(void): Money()
{
	this->dol = 0;
}
Dollar::~Dollar(void)
{

}
Dollar::Dollar(int F, int S, int D): Money(F, S)
{
	this->dol = D;
}
Dollar::Dollar(const Dollar& pair)
{
	this->rub = pair.rub;
	this->kop = pair.kop;
	this->dol = pair.dol;
}
void Dollar::set_dol(int D)
{
	this->dol = D;
}

float Dollar::operator / (const Dollar& c)
{
	float course = 75.61;
	int temp1 = (this->dol * course) * 100,
		temp2 = c.rub * 100 + c.kop;
	float temp3 = temp1 / temp2;
	return temp3;
}

Dollar& Dollar::operator - (const Dollar& c)
{
	float course = 75.61;
	int temp1 = (this->dol * course) * 100,
		temp2 = c.rub * 100 + c.kop;
	int temp3 = temp1 - temp2;
	this->rub = temp3 / 100;
	this->kop = temp3 % 100;
	return *this;
}

Dollar& Dollar::operator + (const Dollar& c)
{
	float course = 75.61;
	int temp1 = (this->dol * course)*100,
		temp2 = c.rub * 100 + c.kop;
	int temp3 = temp1 + temp2;
	this->rub = temp3 / 100;
	this->kop = temp3 % 100;
	return *this;
}


Dollar& Dollar::operator=(const Dollar& k)
{
	if (&k == this)return*this;
	this->rub = k.rub;
	this->kop = k.kop;
	this->dol = k.dol;
	return *this;
}
istream& operator >> (istream& in, Dollar& c)
{
	int n;
	cout << "Рубли: "; in >> c.rub;
	cout << "Копейки: "; in >> c.kop;
	cout << "$$$: "; in >> c.dol;
	if (c.kop > 100)
	{
		n = c.kop / 100;
		c.rub = c.rub + n;
		c.kop = c.kop % 100;
	}
	return in;

}
ostream& operator << (ostream& out, const Dollar& c)
{
	out << "Рубли: " << c.rub;
	cout << endl;
	out << "Копейки: " << c.kop;
	cout << endl;
	out << "$$$: " << c.dol;
	cout << endl;
	out << endl;
	return out;

}
void Dollar::show()
{
	cout << "Рубли: " << rub;
	cout << endl;
	cout << "Копейки: " << kop;
	cout << endl;
	cout << "$$$: " << dol;
	cout << endl;
	cout << endl;
}