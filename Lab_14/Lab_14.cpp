
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int n = 100;

struct man
{
    string name;
    string passport;
    string address;
};

man* arr = new man[n];

int vvodfromfile()
{
    string a;
    ifstream str("Struct.txt");
    for (int i = 0; i < n; i++)
    {
        if (str.is_open()) {
            if (getline(str, a))
            {
                arr[i].name = a;
            }
            if (getline(str, a))
            {
                arr[i].passport = a;
            }
            if (getline(str, a))
            {
                arr[i].address = a;
            }
        }
    }
    str.close();

}

int writte()
{
    string a;
    ofstream str;
    str.open("Struct.txt");
    for (int i = 0; i < n; i++) {
        str << arr[i].name << endl;
        str << arr[i].passport << endl;
        str << arr[i].address << endl;
    }
    str.close();
}

int print()
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "-й человек:   " << endl;
        cout << " " << arr[i].name << endl;
        cout << " " << arr[i].passport << endl;
        cout << " " << arr[i].address << endl;
    }

}

int kmp_ser(string str, string key)
{
    int stl = str.size();
    int ctl = key.size();
    if (stl != 0 && ctl != 0 && stl > ctl)
    {
        int  i, j = 0, k = -1;
        int* pf = new int[1000];
        pf[0] = -1;
        while (j < ctl - 1)
        {
            while (k >= 0 && key[j] != key[k])
            {
                k = pf[k];
            }
            j++;
            k++;
            if (key[j] == key[k])
            {
                pf[j] = pf[k];
            }
            else
            {
                pf[j] = k;
            }
        }
        i = 0;
        j = 0;
        while (j < ctl && i < stl)
        {
            while (j >= 0 && str[i] != key[j])
            {
                j = pf[j];
            }
            i++;
            j++;
        }
        delete[] pf;
        if (j == ctl)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int mur_ser()
{
    string ct;
    cout << "Поиск: ";
    getline(cin, ct);
    getline(cin, ct);
    string st;
    int stl, ctl;
    int answer;
    bool m = true, pp = true;
    for (int z = 0; z < n; z++) {
        st = arr[z].address;
        stl = st.size();
        ctl = ct.size();
        if (stl != 0 && ctl != 0 && stl >= ctl)
        {
            int i, p;
            int b[256];
            for (i = 0; i < 256; i++)
            {
                b[i] = ctl;
            }
            for (i = ctl - 2; i >= 0; i--)
            {
                if (b[int((unsigned char)ct[i])] == ctl)
                {
                    b[int((unsigned char)ct[i])] = ctl - i - 1;
                }
            }
            p = ctl - 1;
            pp = true;
            while (p < stl && pp == true)
            {
                if (ct[ctl - 1] != st[p])
                {
                    p += b[int((unsigned char)st[p])];
                }
                else
                {
                    for (i = ctl - 1; i >= 0; i--)
                    {
                        if (ct[i] != st[p - ctl + i + 1])
                        {
                            p += b[int((unsigned char)st[p])];
                            break;
                        }
                        else if (i == 0)
                        {
                            cout << "Номер элемента: " << i + 1 << endl;
                            cout << "Человек: " << endl;
                            cout << " " << arr[i].name << endl;
                            cout << " " << arr[i].passport << endl;
                            cout << " " << arr[i].address << endl;
                            m = false;
                            pp = false;
                        }
                    }
                }
            }
        }
    }
    if (m == true) {
        cout << "Такого элемента нет." << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    bool m = true;
    int k, ser, key;

    while (m == true)
    {
        cout << "1: Заполнить структуру данными из файла." << endl;
        cout << "2: Записать структуру в файл." << endl;
        cout << "3: Вывести структуру на экран." << endl;
        cout << "4: Поиск по ФИО." << endl;
        cout << "0: Выход." << endl << endl;
        cout << "/: ";
        cin >> k;
        switch (k) {
        case(1):
            vvodfromfile();
            break;
        case(2):
            writte();
            break;
        case(3):
            print();
            break;
        case(4):
            cout << "1: Поиск с помощью метода Кнута-Морриса-Пратта." << endl;
            cout << "2: Поиск с помощью метода Бойера-Мура." << endl;
            cout << "0: Вернуться в меню." << endl << endl;
            cin >> ser;
            switch (ser) {
            case(1):
                cout << "Enter the key: ";
                getline(cin, key);
                getline(cin, key);
                for (int i = 0; i < n; i++) {
                    if (kmp(arr[i].address, key)) {
                        cout << "Номер элемента: " << i + 1 << endl;
                        cout << "Человек: " << endl;
                        cout << " " << arr[i].name << endl;
                        cout << " " << arr[i].passport << endl;
                        cout << " " << arr[i].address << endl;
                        m = false;
                    }
                }
                if (m == true) {
                    cout << "There is no element with this key" << endl;
                }
                break;
            case(2):
                mur_ser();
                break;
            case(0):
                break;
            }
            break;
        case(0):
            m = false;
            break;
        }

    }

    return(0);
}
