#include "fraction.h"
#include <iostream>
using namespace std;

void fraction::Init(double F, int S)
{
	first = F;
	second = S;
}

void fraction::Read()
{
	int h = 25, h2 = -1, m = 60, m2 = -1;
	setlocale(LC_ALL, "ru");
	cout << "Часы: ";
	while (h > 24 && h2 < 0)
	{
		cin >> first;
		h = first;
		h2 = first;
	}
	
	if (h != 24)
	{
		cout << "Минуты: ";
		while (m > 59 && m2 < 0)
		{
			cin >> second;
			m = second;
			m2 = second;
		}
	}
	else
	{
		second = 0;
	}
}

void fraction::Show() 
{
	setlocale(LC_ALL, "ru");
	if (first < 10)
	{
		cout << "Время 0" << first << " : ";
	}
	else
	{
		cout << "Время " << first << " : ";
	}

	if (second > 9)
	{
		cout << second << endl << endl;
	}
	else
	{
	cout << "0" << second << endl << endl;
	}
}

int fraction::minutes(double h, int m)
{
	int time;
	h = h * 60;
	time = h + m;
	return(time);
}