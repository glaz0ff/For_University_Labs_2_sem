
/*
* ����_�����(PAIR)
* ������ ����� int first
* ������ ����� int second
* ���������� ������ ��������� ����� � �������� �������� ��� (a, b)+(c, d)=(a+b,c+d)
* ������� ����������� ����� ��������_�����(MONEY), � ������ ����� � �������.
* �������������� �������� �������� � ���������� �������� ��������� � ������� �������� ����.
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

    cout << "   �������� ��������: " << endl;
    cout << " 1: �������";
    cout << " 2: ���������";
    cout << " 3: ��������";
    cout << "   ��� �����: ";
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