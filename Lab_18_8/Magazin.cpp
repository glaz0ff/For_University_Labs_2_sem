#include "Object.h"
#include "Print.h"
#include "Magazin.h"
#include <string>
#include <iostream>
using namespace std;

Magazin::Magazin(void) :Print()
{
	nop = 0;
}
Magazin::~Magazin(void)
{
}
Magazin::Magazin(string M, string C, int G) :Print(M, C)
{
	nop = G;
}
Magazin::Magazin(const Magazin& L)
{
	name = L.name;
	author = L.author;
	nop = L.nop;
}
void Magazin::Set_nop(int G)
{
	nop = G;
}
Magazin& Magazin::operator=(const Magazin& l)
{
	if (&l == this)return *this;
	name = l.name;
	author = l.author;
	return *this;
}
void Magazin::Show()
{
	cout << "\nname : " << name;
	cout << "\nauthor : " << author;
	cout << "\nnop : " << nop;
	cout << "\n";
}
void Magazin::Input()
{
	cout << "\nname:"; cin >> name;
	cout << "\nauthor:"; cin >> author;
	cout << "\nnop : "; cin >> nop;
}
