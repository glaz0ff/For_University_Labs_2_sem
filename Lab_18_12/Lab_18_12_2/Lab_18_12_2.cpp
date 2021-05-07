
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


#include <iostream>
#include "Time.h"
#include <set>

using namespace std;
typedef set<int, less<int>> tset;
tset::iterator it;

tset make_set(int n) {
    tset m;
    int a;
    for (int i = 0; i < n; ++i) {
        cout << "?";
        cin >> a;
        m.insert(make_pair(i, a));
    }
    return m;
}

void print_set(tset m) {
    for (int i = 0; i < m.size(); ++i) {
        cout << i << ':' << m[i] << endl;
    }
}

tset add_mean(tset q, int k) 
{
    int mf = 100;
    int ms = 100;
    for (auto i : q)
    {
        if (i.get_min() < mf && i.get_sec() < ms)
        {
            ms = i.get_min();
            mf = i.get_sec();
        }
    }
    auto li = q.begin();
    advance(li, k - 1);
    q.insert(li, Time(ms, mf));
    return q;
}

tset del_set(tset q)
{
    tset temp;
    int mi = 0, ma = 0;
    for (auto i : q)
    {
        mi += i.get_min();
        ma += i.get_sec();
    }
    mi /= int(q.size());
    ma /= int(q.size());
    for (auto i : q)
    {

        if (i.get_min() > mi, i.get_sec() > ma)
        {
            temp.erase(i);
        }
    }
    return temp;
}

tset multiplyer(tset q)
{
    tset sd;
    int mn = 0, Min, Sec;
    int max = 0;
    for (auto i : q)
    {
        mn = i.get_min() * 60 + i.get_sec();
        if (max < mn)
        {
            max = mn;
        }
    }
    for (auto i : q)
    {
        mn = i.get_min() * 60 + i.get_sec();
        mn *= max;
        i.set_min(mn / 60);
        i.set_sec(mn % 60);
        sd.insert(i);
    }
    return sd;
}



int main()
{
    int n;
    cout << "N?";
    cin >> n;
    tset m = make_set(n);
    print_set(m);
    cout << "Pos?";
    cin >> n;
    m = add_mean(m, n);
    print_set(m);
    m = del_set(m);
    print_set(m);
    m = multiplyer(m);
    print_set(m);

    return 0;
}
