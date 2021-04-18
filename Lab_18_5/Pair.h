#pragma once
#include <iostream>
using namespace std;

class Pair
{
protected:
	int first;
	int second;
public:
	Pair(void);
	void show();
public:
	virtual ~Pair(void);
	Pair(int, int);
	Pair(const Pair&);

	int get_first() { return first; }
	int get_second() { return second; }
	void set_first(int);
	void set_second(int);

	Pair& operator + (const Pair&);
	Pair& operator = (const Pair&);
	friend istream& operator >> (istream& in, Pair& c);
	friend ostream& operator << (ostream& out, const Pair& c);
};
