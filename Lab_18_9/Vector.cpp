#include <iostream>
#include "Vector.h"
using namespace std;

Vector::Vector(int s, int k)
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
	beg.elem = &data[0];
	end.elem = &data[size];
}
Vector::Vector(const Vector& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
}
Vector::~Vector()
{
	delete[]data;
	data = 0;
}
Vector& Vector::operator=(const Vector& a)
{
	if (this == &a) return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
	beg = a.beg;
	end = a.end;
	return *this;
}
int& Vector::operator[](int index)
{
	if (index < 0) throw 2;
	if (index >= size) throw 3;
	if (index < size) return data[index];
	else cout << "Error.";
}
Vector Vector::operator+(const int k)
{
	Vector temp(size);
	for (int i = 0; i < size; i++)
		temp.data[i] += data[i] + k;
	return temp;
}
Vector& Vector::operator*(const Vector& t)
{
	for (int i = 0; i < size; i++)
	{
		data[i] = data[i] * t.data[i];
	}
	return*this;
}
Iterator Iterator::operator+(const int n)
{
	Iterator yu;
	yu.elem = elem + n;
	return yu;
}
int Vector::operator()()
{
	return len();
}
ostream& operator<<(ostream& out, const Vector& a)
{
	for (int i = 0; i < a.size; i++)
		out << a.data[i] << " ";
	return out;
}
istream& operator>>(istream& in, Vector& a)
{
	for (int i = 0; i < a.len(); i++)
		in >> a.data[i];
	return in;
}