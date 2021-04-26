#pragma once
#include "Object.h"
#include "Print.h"
#include <string>
#include <iostream>
using namespace std;

class Magazin :
	public Print
{
public:
	Magazin(void);
public:
	~Magazin(void);
	void Show();
	void Input();
	Magazin(string, string, int);
	Magazin(const Magazin&);
	int Get_nop() { return nop; }
	void Set_nop(int);
	Magazin& operator=(const Magazin&);
protected:
	int nop;
};