/*

Задача 1
1. Контейнер - set
2. Тип элементов - float

Задача 2
Тип элементов Time (см. лабораторную работу №3).

Задача 3
Параметризированный класс – Вектор (см. лабораторную работу №7)

Задание 3
Найти минимальный
элемент и добавить его на
заданную позицию
контейнера

Задание 4
Найти элементы большие
среднего
арифметического и
удалить их из контейнера

Задание 5
Каждый элемент домножить на
максимальный элемент
контейнера

*/

#include "Vector.h"
#include "Time.h"
#include <iostream>
using namespace std;

typedef Vector<Time> lst;

int main()
{
    try
    {
        lst l;
        int n;
        cout << "N? ";
        cin >> n;
        l.make(n);
        l.print();

        cout << "Pos?";
        cin >> n;
        l.add_mean(n);
        l.print();

        l.del();
        l.print();

        l.decrease_mean();
        l.print();
    }
    catch (int)
    {
        cout << "error!";
    }

    return(0);

}

