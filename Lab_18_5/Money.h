#pragma once
#include <iostream>
using namespace std;

class Money
{
protected:
	int rub;
	int kop;
public:

	Money(void);
	virtual~Money();
	Money(int, int);
	Money(const Money&);

	int get_rub() { return rub; }
	int get_kop() { return kop; }
	void set_rub(int);
	void set_kop(int);

	float operator / (const Money&);
	Money& operator - (const Money&);
	Money& operator = (const Money&);
	Money& operator + (const Money&);

	friend istream& operator >> (istream& in, Money& c);
	friend ostream& operator << (ostream& out, const Money& c);
};