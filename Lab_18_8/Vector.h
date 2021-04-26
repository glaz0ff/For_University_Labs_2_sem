#pragma once
#include "Object.h"
#include "Print.h"
#include "Magazin.h"
#include <string>
#include <iostream>
using namespace std;

class Vector
{
public:
	Vector(int);
public:
	~Vector(void);
	void Add();
	void Del();
	void Show();
	int operator()();
	virtual void HandleEvent(const TEvent& e);
protected:
	Object** beg;
	int size;
	int cur;
};