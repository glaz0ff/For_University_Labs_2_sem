#pragma once
#include "Money.h"
class Dollar:
	public Money
{
protected:
	int dol;
public:
	void show();
	Dollar(void);
	virtual~Dollar();
	Dollar(int, int, int);
	Dollar(const Dollar&);

	int get_dol() { return dol; }
	void set_dol(int);

	float operator / (const Dollar&);
	Dollar& operator - (const Dollar&);
	Dollar& operator = (const Dollar&);
	Dollar& operator + (const Dollar&);

	friend istream& operator >> (istream& in, Dollar& c);
	friend ostream& operator << (ostream& out, const Dollar& c);
};