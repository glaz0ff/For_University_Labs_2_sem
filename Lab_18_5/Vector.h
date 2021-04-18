#pragma once
#include <iostream>
#include "Pair.h"

using namespace std;

class Vector
{
public:
	Vector(void);
	Vector(int);
public:
	~Vector(void);
	void add(Pair*p);
	friend ostream& operator << (ostream& out, const Vector& c);
private:
	Pair** beg;
	int size;
	int cur;
};