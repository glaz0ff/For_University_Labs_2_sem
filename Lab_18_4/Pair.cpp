#include "Pair.h"
#include <iostream>
using namespace std;

Pair::Pair(void)
{
	this->first = 0;
	this->second = 0;
}
Pair::~Pair(void)
{

}
Pair::Pair(int F, int S)
{
	this->first = F;
	this->second = S;
}
Pair::Pair(const Pair& pair)
{
	this->first = pair.first;
	this->second = pair.second;
}
void Pair::set_first(int F)
{
	this->first = F;
}
void Pair::set_second(int S)
{
	this->second = S;
}

Pair& Pair::operator+(const Pair& c)
{
	int temp1 = this->first, 
		temp2 = this->second, 
		temp3 = c.first, 
		temp4 = c.second;
	this->first = temp1 + temp2;
	this->second = temp3 + temp4;
	return *this;
}

Pair& Pair::operator=(const Pair& k)
{
	if (&k == this)return*this;
	this->first = k.first;
	this->second = k.second;
	return *this;
}
istream& operator >> (istream& in, Pair& c)
{
	cout << "First? "; in >> c.first;
	cout << "Second? "; in >> c.second;
	return in;

}
ostream& operator << (ostream& out, const Pair& c)
{
	out << "First: " << c.first;
	cout << endl;
	out << "Second: " << c.second;
	cout << endl;
	out << endl;
	return out;

}