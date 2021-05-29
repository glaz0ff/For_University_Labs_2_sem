
#include <iostream>
#include "Header.h"
using namespace std;


int main()
{
    btree t;
    int n;

    cout << "N? ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        char a;
        cin >> a;
        t.insert(a);
    }

    t.print();
    t.kol();
}