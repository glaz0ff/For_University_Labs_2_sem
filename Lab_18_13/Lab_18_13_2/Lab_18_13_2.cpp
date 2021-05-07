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
#include "Time.h"
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

typedef vector<Time>vec;
typedef list<Time>lst;

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

vec make_vec(int n) {
    vec q;
    Time p;
    for (int i = 0; i < n; i++) {
        cin >> p;
        q.push_back(p);
    }
    return q;
}

lst copy_vec_to_lst(vec q) {
    lst l;
    int b = 0;
    while (!q.empty()) {
        l.push_back(q[b]);
        q.pop_back();
        b++;
    }
    return l;
}
vec copy_lst_to_vec(lst l) {
    vec q;
    while (!l.empty()) {
        q.push_back(l.back());
        l.pop_back();
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


int main()
{
    int n;
    cout << "N? ";
    cin >> n;
    vec v = make_vec(n);
    print_vec(v);

    lst l = copy_vec_to_lst(v);
    cout << "Pos?";
    cin >> n;
    lst::const_iterator it;
    it = min_element(l.begin(), l.end());
    auto li = l.begin();
    advance(li, n);
    l.insert(li, *it);
    vec t = copy_lst_to_vec(l);
    print_vec(t);

    mean m = for_each(l.begin(), l.end(), mean());
    Time p = m.get_result();
    l.remove_if([p](Time& m) { return (m > p); });
    vec o = copy_lst_to_vec(l);
    print_vec(o);

    lst::const_iterator ot;
    ot = max_element(l.begin(), l.end());
    for_each(l.begin(), l.end(), [ot](Time& p) { p = p * (*ot); });
    vec e = copy_lst_to_vec(l);
    print_vec(e);


    return 0;

}

