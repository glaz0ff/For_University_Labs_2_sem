/*
Задание:  Удалить все записи из интервала от k1 до k2,
где k1 и k2 переменные типа Time. 
 Увеличить все записи с заданным значением на 1 минуту 30 секунд. 
 Добавить К записей в начало файла.
*/
#include "Time.h"
#include <iostream>
#include <fstream>
#include "file_time.h"
#include <string>

using namespace std; 

using namespace std;
void main()
{
	setlocale(LC_ALL, "ru");

	Time k1, k2;
	Time p;
	Time er;
	int u;
	int k, c;
	char file_name[30];
	do
	{ 
		cout << "\n1. Make file";
		cout << "\n2. Print file";
		cout << "\n3. Delete////";
		cout << "\n4. Add////";
		cout << "\n5  Plus////";
		cout << "\n0. Exit\n";
		cin >> c;
		switch (c)
		{
		case 1: 
			cout << "file name?"; cin >> file_name;
			k = make_file(file_name);
			if (k < 0)cout << "Can't make file";
			break;
		case 2:
			cout << "file name?"; cin >> file_name;
			k = print_file(file_name);
			if (k == 0)cout << "Empty file\n";
			if (k < 0)cout << "Can't read file\n";
			break;
		case 3: 
			cout << "file name?"; cin >> file_name;
			
			cout << "Time 1, 2?" << endl;
			cin >> k1 >> k2;
			k = del_file(file_name, k1, k2);
			if (k < 0)cout << "Can't read file";
			break;
		case 4:
			cout << "file name?"; cin >> file_name;
			cout << "k?";
			cin >> u;
			k = add_file(file_name, u);
			if (k < 0)cout << "Can't read file";
			break;
		case 5:
			cout << "file name?"; cin >> file_name;
			cout << "k?";
			cin >> er;
			k = plus_file(file_name, er);
			if (k < 0)cout << "Can't read file";
			break;
		}
	} while (c != 0);
}