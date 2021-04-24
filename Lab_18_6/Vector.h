#pragma once
#include <iostream>
using namespace std;

class Vector
{
	int len() { return size; }
public:
	Vector(int s, int k = 0);
	Vector(const Vector& a);
	~Vector();
	Vector& operator=(const Vector& a);
	int& operator[](int index);
	Vector operator+(const int k);
	Vector& operator*(const Vector& t);
	int operator()();
	friend ostream& operator<<(ostream& out, const Vector& a);
	friend istream& operator>>(istream& in, Vector& a);

	Iterator first() { return beg; }
	Iterator last() { return end; }

private:
	int size;
	int* data;

	Iterator beg;
	Iterator end;
};

class Iterator
{
	friend class Vector;
private:
	int* elem;
public:
	Iterator() { elem = 0; }
	Iterator(const Iterator& it) { elem = it.elem; }
	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; }
	int operator*()const { return *elem; }
	Iterator operator+(const int n);
};
