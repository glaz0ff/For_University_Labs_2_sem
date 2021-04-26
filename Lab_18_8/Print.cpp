#include "Object.h"
#include "Print.h"
#include "Magazin.h"
#include <string>
#include <iostream>
using namespace std;

Print::Print(void)
{
	name = "";
	author = "";
}
Print::~Print(void)
{
}
Print::Print(string M, string C)
{
	name = M;
	author = C;

}
Print::Print(const Print& car)
{
	name = car.name;
	author = car.author;
}
void Print::Set_author(string C)
{
	author = C;
}
void Print::Set_name(string M)
{
	name = M;
}
Print& Print::operator=(const Print& c)
{
	if (&c == this)return *this;
	name = c.name;
	author = c.author;
	return *this;
}
void Print::Show()
{
	cout << "\nname : " << name;
	cout << "\nauthor : " << author;
	cout << "\n";
}
void Print::Input()
{
	cout << "\nname:"; cin >> name;
	cout << "\nauthor:"; cin >> author;
}

void Print::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//событие-сообщение
	{
		switch (e.command)
		{
		case cmGet:
			cout << "name=" << Get_name() << endl;
			cout << "author=" << Get_author() << endl;
			break;
		}
	}
}