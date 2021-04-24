
#include <iostream>
#include "Vector.h"
using namespace std;

void main()
{
    setlocale(LC_ALL, "ru");
    Vector a(5);
    cout << a << endl;
    cin >> a;
    cout << a << endl;
    a[2] = 100;
    cout << a << endl;
    Vector b(10);
    cout << b << endl;
    b = a; 
    cout << b << endl;
    Vector c(10);
    c = b + 100;
    cout << c << endl;
    cout << "Длинна вектора с = " << c() << endl;
    Vector d(5);
    cin >> d;
    cout << d;
    a = a * d;
    cout << a << endl;

    cout << *(a.first()) << endl;
    Iterator i = a.first();
    int n, k = 1;
    cout << " Введите номер элемента: ";
    cin >> n;
    i = i + n;
    cout << *i << endl;
    for (i = a.first(); i != a.last(); i + k)cout << *i << endl;
}
