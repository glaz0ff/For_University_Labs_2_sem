
/*
Задача 1
1. Контейнер - список
2. Тип элементов Time (см. лабораторную работу №3).
Задача 2
Адаптер контейнера - вектор.
Задача 3
Ассоциативный контейнер - множество

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

#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include "Time.h"
#include <random>

using namespace std;
typedef list<Time> lst;

struct mean 
{
    void operator()(Time p)
    {
        ++n;
        s_f += p.get_min();
        s_s += p.get_sec();
    }

    Time get_result() { return Time(s_f / n, s_s / n); }

    
private:
    int n{ 0 };
    int s_f{ 0 };
    int s_s{ 0 };
};

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

void print_list(lst l)
{
    for (auto i : l)
    {
        cout << i << endl;
    }
    cout << endl;
}

int main() {
    lst l;
    int n;

    cout << "N? ";
    cin >> n;
    l = make_list(n);
    print_list(l);

    cout << "Pos?";
    cin >> n;
    lst::const_iterator it;
    it = min_element(l.begin(), l.end());
    auto li = l.begin();
    advance(li, n);
    l.insert(li, *it);
    print_list(l);

    mean m = for_each(l.begin(), l.end(), mean());
    Time p = m.get_result();
    l.remove_if([p](Time& m) { return (m > p); });
    print_list(l);

    lst::const_iterator ot;
    ot = max_element(l.begin(), l.end());
    for_each(l.begin(), l.end(), [ot](Time& p) { p = p * (*ot); });
    print_list(l);


    return 0;
}