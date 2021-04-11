#pragma once
#include <iostream>
using namespace std;

class yravnenie
{
	double A;
	double B;
	double C;

public:
	yravnenie();
	yravnenie(double, double, double);
	yravnenie(const yravnenie& t);
	~yravnenie();

	double get_A();
	void set_A(double);
	double get_B();
	void set_B(double);
	double get_C();
	void set_C(double);
	void show();
};
