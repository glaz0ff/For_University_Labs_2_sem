#include <iostream>
#include <set>

using namespace std;
typedef set<int, float> tset;
typedef tset::iterator it;

tset make_map(int n) {
    tset m;
    int a;
    for (int i = 0; i < n; ++i) {
        cout << "?";
        cin >> a;
        m.insert(make_pair(i, a));
    }
    return m;
}

void print_map(tset m) {
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
    q.insert(li, make_pair(ms, mf));
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


int main() {
    int n;
    cout << "N?";
    cin >> n;
    tset m = make_map(n);
    print_map(m);

    cout << "Pos?";
    cin >> n;
    m = add_mean(m, n);
    print_map(m);

    m = del_set(m);
    print_map(m);

    m = multiplyer(m);
    print_map(m);

    return 0;
}