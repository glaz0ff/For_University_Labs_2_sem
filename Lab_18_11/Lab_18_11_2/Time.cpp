
#include "Time.h"
#include <iostream>
using namespace std;

Time& Time::operator=(const Time& t)
{
	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}



Time& Time::operator -- ()
{
	int temp = min * 60 + sec;
	temp--;
	min = temp / 60;
	sec = temp % 60;
	return *this;
}

Time Time::operator -- (int)
{
	int temp = min * 60 + sec;
	temp--;
	Time t(min, sec);
	min = temp / 60;
	sec = temp % 60;
	return t;
}

Time Time::operator- (const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 + temp2) / 2;
	p.sec = (temp1 + temp2) % 2;
	return p;
}

bool Time::operator== (const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	return temp1 == temp2;
}

bool Time::operator!= (const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	return temp1 != temp2;
}
bool Time::operator<(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	return temp1 < temp2;
}

istream& operator>>(istream& in, Time& t)
{
	int n = 0;
	cout << "min? ";
	in >> t.min;
	cout << "sec? ";
	in >> t.sec;
	while (t.sec > 60)
	{
		n = t.sec / 60;
		t.sec = t.sec % 60;
		t.min = t.min + n;
	}
	return in;
}

ostream& operator<<(ostream& out, const Time& t)
{
	return (out << "Time: " << t.min << " : " << t.sec);
}