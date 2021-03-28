
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

int lin_ser()
{
    string a;
    bool pp = true;
    cout << "Введите: ";
    getline(cin, a);
    getline(cin, a);
    for (int i = 0; i < n; i++) 
    {
        if (arr[i].address == a)
        {
            cout << "Номер элемента: " << i + 1 << endl;
            cout << "Человек: " << endl;
            cout << " " << arr[i].name << endl;
            cout << " " << arr[i].passport << endl;
            cout << " " << arr[i].address << endl;
            pp = false;
        }
    }
    if (pp == true)
    {
        cout << "Такого элемента нет." << endl;
    }
}

int prm_ser()
{
   string substr;
    cout << "enter the substring: ";
    getline(cin, substr);
    getline(cin, substr);
    string str;
    bool x = true, p = true;
    for (int i = 0; i < n; i++)
    {
        str = arr[i].address;
        for (int j = 0; j < str.size(); j++) 
        {
            x = true;
            for (int k = 0; k < substr.size(); k++)
            {
                if (substr[k] != str[j + k])
                {
                    x = false;
                }
            }
            if (x == true) {
                cout << "номер элемента: " << i + 1 << endl;
                cout << "человек: " << endl;
                cout << " " << arr[i].name << endl;
                cout << " " << arr[i].passport << endl;
                cout << " " << arr[i].address << endl;
               p = false;
            }
        }
    }
    if (p == true)
    {
        cout << "такого элемента нет." << endl;
    }
}

int int_ser()
{
    int* art = new int[n];
    int sum;
    string str;
    for (int i = 0; i < n; i++)
    {
        str = arr[i].address;
        sum = 0;
        for (int j = 0; j < str.size(); j++)
        {
            sum += str[j];
        }
        art[i] = sum;
    }
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (art[j] < art[min]) 
            {
                min = j;
            }
        }
        temp = art[i];
        art[i] = art[min];
        art[min] = temp;
    }
    string key;
    int sumkey = 0;
    cout << "Enter the key: ";
    getline(cin, key);
    getline(cin, key);
    for (int i = 0; i < key.size(); i++) 
    {
        sumkey += key[i];
    }
    int mid, left = 0, right = n - 1;
    int answer;
    bool z = true;
    while (art[left] <= sumkey && art[right] >= sumkey && z) 
    {
        mid = left + ((sumkey - art[left]) * (right - left)) / (art[right] - art[left]);
        if (art[mid] < sumkey) {
            left = mid + 1;
        }
        else {
            if (art[mid] > sumkey)
            {
                right = mid - 1;
            }

            else 
            {
                answer = mid;
                z = false;
            }
        }
    }
    sum = 0;
    int l = 0;
    if (z == true) {
        if (art[left] == sumkey) 
        {
            answer = left;
        }
        else 
        {
            answer = -1;
        }
    }
    if (answer > -1) {
        for (int i = 0; i < n; i++) 
        {
            str = arr[i].address;
            sum = 0;
            for (int j = 0; j < str.size(); j++) 
            {
                sum += str[j];
            }
            if (sum == art[answer]) {
                cout << "Номер элемента: " << i + 1 << endl;
                cout << "Человек: " << endl;
                cout << " " << arr[i].name << endl;
                cout << " " << arr[i].passport << endl;
                cout << " " << arr[i].address << endl;
            }
        }
    }
    else {
        cout << "Такого элемента нет." << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    bool m = true;
    int k, ser;

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
            cout << "1: Линейный поиск." << endl;
            cout << "2: Прямой поиск." << endl;
            cout << "3: Интерполяционный поиск." << endl;
            cout << "0: Вернуться в меню." << endl << endl;
            cin >> ser;
            switch (ser) {
            case(1):
                lin_ser();
                break;
            case(2):
                prm_ser();
                break;
            case(3):
                int_ser();
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