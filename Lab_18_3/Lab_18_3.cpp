
#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    Time a;
    Time b;
    Time c;

    cin >> a;
    cin >> b;
    cin >> c;

    int n;
    cout << "������� ����������� ������, ������� ������ �������: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a--;
    }
    cout << a << endl << endl;
    cout << b << endl;
    cout << c << endl << endl;

    if (b == c)
    {
        cout << b << " ����� " << c << endl;
    }
    if (b != c)
    {
        cout << b << " �� ����� " << c << endl;
    }
   
}
