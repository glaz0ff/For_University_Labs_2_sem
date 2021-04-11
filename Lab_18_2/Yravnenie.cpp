
#include "Yravnenie.h"
#include <iostream>
using namespace std;

yravnenie::yravnenie()
{
	A = 0;
	B = 0;
	C = 0;
}
yravnenie::yravnenie(double a, double b, double c)
{
	A = a;
	B = b;
	C = c;
	cout << "Конструктор с параметрами" << this << endl;
}
yravnenie::yravnenie(const yravnenie& t)
{
	A = t.A;
	B = t.B;
	C = t.C;
	cout << "Конструктор копирования" << this << endl;
}
yravnenie::~yravnenie()
{
	cout << "Деконструктор" << this << endl;
}

double yravnenie::get_A()
{
	return A;
}
double yravnenie::get_B()
{
	return B;
}
double yravnenie::get_C()
{
	return C;
}

void yravnenie::set_A(double a)
{
	A = a;
}
void yravnenie::set_B(double b)
{
	B = b;
}
void yravnenie::set_C(double c)
{
	C = c;
}

void yravnenie::show()
{
	cout << "A: " << A << endl;
	cout << "B: " << B << endl;
	cout << "C: " << C << endl;
}

