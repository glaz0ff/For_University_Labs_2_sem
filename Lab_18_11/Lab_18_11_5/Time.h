#pragma once
#include <iostream>
using namespace std;
class Time
{
public:
	Time(void);
	Time(int, int);
	Time(const Time&);
	int get_min() { return min; }
	int get_sec() { return sec; }
	void set_min(int m) { min = m; }
	void set_sec(int s) { sec = s; }
	Time& operator=(const Time&);
	Time& operator>(const Time&);
	friend ostream& operator<< (ostream& out, const Time&);
	friend istream& operator>> (istream& in, Time&);

	Time operator+(Time k);
public:
	virtual ~Time(void) {};
private:
	int min, sec;
};

