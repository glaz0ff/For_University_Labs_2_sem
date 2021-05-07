/*
* Задача 1
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

#include <iostream>
#include "Time.h"
#include <list>
#include <cstdlib>
#include <iterator>
#include <random>

using namespace std;
typedef list<Time>lst;

lst make_list(int n)
{
    lst l;
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<double> distr(0, 59);
    for (int i = 0; i < n; ++i)
    {
        Time p;
        p.set_min(distr(eng));
        p.set_sec(distr(eng));
        l.push_back(p);
    }
    return l;
}

void print_list(lst l, int o) 
{
    cout << o << ": " << endl;
    for (auto i : l)
    {
        cout << i << ' ' << endl;
    }
    cout << endl << endl;
}

lst add_mean(lst l, int k)
{
    int mn = 0, Min, Sec;
    int min = 10000;
    for (auto i: l)
    {
        mn = i.get_min() * 60 + i.get_sec();
        if (mn < min)
        {
            min = mn;
        }
    }
    auto li = l.begin();
    advance(li, k - 1);
    Min = min / 60;
    Sec = min % 60;
    l.insert(li, Time(Min, Sec));
    return l;

}

lst del_list(lst l)
{
    lst temp;
    int mn = 0, sredn, srednmin, srednsec;
    for (auto i : l)
    {
        mn += i.get_min() * 60 + i.get_sec();
    }
    sredn = mn / int(l.size());
    srednmin = sredn / 60;
    srednsec = sredn % 60;
    for (auto i : l)
    {
        if (i < Time(srednmin, srednsec))
        {
            temp.push_back(i);
        }
    }
    return temp;
}

lst multiplyer(lst l)
{
    lst sd;
    int mn = 0, Min, Sec;
    int max = 0;
    for (auto i : l)
    {
        mn = i.get_min() * 60 + i.get_sec();
        if (max < mn)
        {
            max = mn;
        }
    }
    for (auto i : l)
    {
        mn = i.get_min() * 60 + i.get_sec();
        mn *= max;
        i.set_min(mn / 60);
        i.set_sec(mn % 60);
        sd.push_back(i);
    }
    return sd;
}

int main()
{
    try 
    {
        lst l, b, a, c;
        auto li = l.begin();
        int n, k, o;
        cout << "N? ";
        cin >> n;
        l = make_list(n);
        o = 1, 2;
        print_list(l, o);

        cout << "Pos? "; cin >> k;
        b = add_mean(l, k);
        o = 3;
        print_list(b, o);

        a = del_list(l);
        o = 4;
        print_list(a, o);

        c = multiplyer(a);
        o = 5;
        print_list(c, o);
    }
    catch(int)
    {
        cout << "error";
    }

}

