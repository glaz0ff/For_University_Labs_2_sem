#include "Object.h"
#include "Print.h"
#include "Magazin.h"
#include "Vector.h"
#include "Dialog.h"
#include <string>
#include <iostream>
using namespace std;

void main()
{
	Print* a = new Print;
	a->Input();
	a->Show();
	Magazin * b = new Magazin;
	b->Input();
	b->Show();

	Print* c = new Print;
	c->Input();
	Magazin* d = new Magazin; 
	d->Input();
	Vector v(10);
	Object* p = c;
	v.Add();
	p = d;
	v.Add(); 
	v.Show();
	v.Del();
	cout << "\nVector size=" << v();

	Dialog D;
	D.Execute();

}

/*

Базовый класс:
ПЕЧАТНОЕ_ИЗДАНИЕ(PRINT)
Название– string
Автор – string
Производный класс
ЖУРНАЛ (MAGAZIN)
Количество страниц - int
Группа – Вектор (Vector).
Команды:  Создать группу (формат команды: m количество элементов группы).
 Добавить элемент в группу (формат команды: +)
 Удалить элемент из группы (формат команды -)
 Вывести информацию об элементах группы (формат команды: s)
 Вывести информацию о названиях всех элементов группы (формат команды : z)
Конец работы (формат команды: q)

*/