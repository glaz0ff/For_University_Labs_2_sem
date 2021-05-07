/*
Задача 1
1. Контейнер - список
2. Тип элементов - float
Задача 2
Тип элементов Time (см. лабораторную работу №3).
Задача 3
Параметризированный класс – Вектор (см. лабораторную работу №7)
Задача 4
Адаптер контейнера - вектор.
Задача 5
Параметризированный класс – Вектор
Адаптер контейнера - стек

Задание 3 
Найти минимальный
элемент и добавить его на
заданную позицию
контейнера.

Задание 4
Найти элементы большие
среднего
арифметического и
удалить их из контейнера.

 Задание 5
Каждый элемент домножить на
максимальный элемент
контейнера.

*/
#include <list>
#include <cstdlib>
#include <iterator>
#include <iostream>

using namespace std;
typedef list<float> lst;

lst make_list(int n) {
    lst l;
    for (int i = 0; i < n; ++i) {
        float a = rand() % 100 - 50;
        l.push_back(a);
    }
    return l;
}

void print_list(lst l, int o)
{
    cout << o << ": ";
    for (auto i : l) 
    {
        cout << i << ' ';
    }
    cout << endl;
}

lst add_mean(lst l, int k) {
    float max = 101;

    for (auto i : l)
    {
        if (i < max)
            max = i;
    }

    auto li = l.begin();
    advance(li, k);
    l.insert(li, max);
    return l;
}

lst domnoj_list(lst l) {
    float max = -1000;
    lst y;
    for (auto i : l)
    {
        if (i > max)
            max = i;
    }

    for (auto i : l)
    {
        y.push_back(i*max);
    }
    
    return y;
}

lst del_list(lst l) 
{
    lst temp;
    int m = 0;
    for (auto i : l)
    {
        m += i;
    }
    m = m / int(l.size());
    for (auto i : l)
    {
        if (i <= m) 
        {
            temp.push_back(i);
        }
    }
    return temp;
}


void main()
{
    try
    {
        list<float> v;
        list<float> p;
        list<float> m;
        list<float>::iterator vi = v.begin();
        int n, k, o;
        cout << "N?"; cin >> n;
        v = make_list(n);
        o = 1, 2;
        print_list(v, o);

        cout << "Pos?";
        cin >> k;
        v = add_mean(v, k-1);
        o = 3;
        print_list(v, o);

        p = del_list(v);
        o = 4;
        print_list(p, o);

        m = domnoj_list(p);
        o = 5;
        print_list(m, o);

    }
    catch (int)
    {
        cout << "error!";
    }
}
