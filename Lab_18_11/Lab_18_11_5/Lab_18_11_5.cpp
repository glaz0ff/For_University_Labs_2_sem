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
#include "Stack.h"
#include "Time.h"
#include <stack>
#include <vector>
using namespace std;

typedef vector<Time>vec;
typedef stack<Time>lst;

vec make_pq(int n) {
    vec q;
    Time p;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        q.push_back(p);
    }
    return q;
}

lst copy_vec_to_lst(vec q) {
    lst l;
    int b = 0;
    while (!q.empty()) {
        l.push(q[b]);
        q.pop_back();
        b++;
    }
    return l;
}

vec copy_lst_to_vec(lst l) {
    vec q;
    while (!l.empty()) {
        q.push_back(l.top());
        l.pop();
    }
    return q;
}

void print_vec(vec q) {
    for (auto i : q)
    {
        cout << i << ' ';
    }
    cout << endl;
}

vec add_mean(vec q, int k) {
    lst l = copy_vec_to_lst(q);
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

vec del_vec(vec q)
{
    lst l = copy_vec_to_lst(q);
    vec temp;
    int mi = 0, ma = 0;
    for (auto i : q)
    {
        mi += i.get_min();
        ma += i.get_sec();
    }
    mi /= int(l.size());
    ma /= int(l.size());
    for (auto i : q)
    {

        if (i.get_min() < mi, i.get_sec() < ma)
        {
            temp.push_back(i);
        }
    }
    return temp;
}

vec multiplyer(vec q)
{
    lst l = copy_vec_to_lst(q);
    lst sd;
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
        sd.push(i);
    }
    vec sp = copy_lst_to_vec(sd);
    return sp;
}



int main()
{
    try {
        int n;
        cout << "N? ";
        cin >> n;
        vec q = make_pq(n);
        print_vec(q);
        int pos;
        cout << "Pos? ";
        cin >> pos;
        q = add_mean(q, pos);
        print_vec(q);
        q = del_vec(q);
        print_vec(q);
        q = multiplyer(q);
        print_vec(q);
    }
    catch (int) {
        cout << "error!";
    }
}



