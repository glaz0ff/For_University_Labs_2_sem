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
#include <set>
#include "Time.h"
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;
typedef set<int, Time> tset;
tset::iterator po;

struct mean
{
    void operator()(pair<int, Time> p) 
    {
        ++n;
        s_f += p.second.get_min();
        s_s += p.second.get_sec();
    }

    Time get_result() { return Time(s_f / n, s_s / n); }

private:
    int n{0};
    int s_f{0};
    double s_s{0};
};

tset make_set(int n) {
    tset m;
    Time p;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        m.insert(make_pair(i, p));
    }
    return m;
}

void print_set(tset m) {
    for (auto i : m) {
        cout << i << endl;
    }
}



int main()
{
    int n;
    cout << "N? ";
    cin >> n;
    tset v = make_set(n);
    print_set(v);

    cout << "Pos?";
    cin >> n;
    tset::const_iterator it;
    it = min_element(v.begin(), v.end());
    auto li = v.begin();
    advance(li, n);
    v.insert(li, *it);
    print_set(v);

    mean m = for_each(v.begin(), v.end(), mean());
    Time p = m.get_result();
    for (auto i : v)
    {
        if (i > p)
        {
            v.erase(i);
        }
    }
    print_set(v);

    tset::const_iterator ot;
    ot = max_element(v.begin(), v.end());
    for_each(v.begin(), v.end(), [ot](Time& p) { p = p * (*ot); });
    print_set(v);




    return 0;

}

