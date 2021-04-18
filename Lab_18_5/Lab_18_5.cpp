
/*
* Пара_чисел(PAIR)
* Первое число int first
* Второе число int second
* Определить методы изменения полей и операцию сложения пар (a, b)+(c, d)=(a+b,c+d)
* Создать производный класс ДЕНЕЖНАЯ_СУММА(MONEY), с полями Рубли и Копейки.
* Переопределить операцию сложения и определить операции вычитания и деления денежных сумм.
*/

#include <iostream>
#include "Vector.h"
#include "Money.h"
#include "Dollar.h" 
#include "Pair.h"
using namespace std;

void main()
{
    setlocale(LC_ALL, "ru");

    Pair a;
    Pair b;
     /*Pair c;


    cin >> a;
    cin >> b;

    cout << a;
    cout << b;

    c = a + b;
    cout << c;

    Money f;
    Money g;
    Money t;
    Money p;

    cin >> f;
    cin >> g;

    cout << f;
    cout << g;
    int ert;

    cout << "   Выберите действие: " << endl;
    cout << " 1: Деление";
    cout << " 2: Вычитание";
    cout << " 3: Сложение";
    cout << "   Ваш выбор: ";
    cin >> ert;
    switch (ert) {
    case 1:
        cout << f / g << endl << endl;
        break;
    case 2:
        t = f - g;
        cout << t;
        break;
    case 3:
        p = f + g;
        cout << p;
        break;
    }*/
    Vector v(5);

    Dollar o;
    Money g;
    cin >> g;
    cin >> o;
    cout << o << endl;
    Dollar* r = &o;
    r->show();

    Pair* p = &a;
    v.add(p);
    p = &b;
    v.add(p);
    cout << v;

}