#include <iostream>
#include "Vector.h"
#include "Money.h"
#include "Dollar.h" 
#include "Pair.h"

Vector::Vector(void)
{
	beg = 0;
	size = 0;
	cur = 0;
}
Vector::~Vector(void)
{
	if (beg != 0) delete[] beg;
	beg = 0;
}
Vector::Vector(int n)
{
	beg = new Pair*[n];
	size = n;
	cur = 0;
}
void Vector::add(Pair* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}
ostream& operator << (ostream& out, const Vector& c)
{
	if (c.size == 0) out << "Empty" << endl;
	Pair** p = c.beg;
	for (int i = 0; i < c.cur; i++)
	{
		(*p)->show();
		p++;
	}
	return out;
}