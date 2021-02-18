#include <iostream>
#include <string>

using namespace std;

struct Man {
	string surname;
	string name;
	int YOB;
	int growth;
	int weight;
};

void Vvod(Man*& person, int num, int k) // ввод данных для первого массива
{
	system("chcp 1251>nul");
	int  YOB1 = -1, growth1 = -1, weight1 = -1;
	for (int i = k; i < num; i++)
	{
		cout << endl;
		cout << "Введите ФИО:\t";
		cin >> person[i].surname;
		getline(cin, person[i].name);
		while ((YOB1 >= 2022 || YOB1 < 0))
		{
			cout << "Год рождения:\t";
			cin >> YOB1;
			if ((YOB1 >= 2022 || YOB1 < 0))
			{
				cout << "Введены некоректные данные!" << endl;
			}
			person[i].YOB = YOB1;
		}
		while (growth1 < 0)
		{
			cout << "Введите рост:\t";
			cin >> growth1;
			if (growth1 <= 0 && growth1 >= 250)
			{
				cout << "Введены некоректные данные!" << endl;
			}
			person[i].growth = growth1;
		}
		while (weight1 < 0)
		{
			cout << "Введите вес:\t";
			cin >> weight1;
			if (weight1 <= 0)
			{
				cout << "Введены некоректные данные!" << endl;
			}
			person[i].weight = weight1;
		}
		YOB1 = -1;
		growth1 = -1;
		weight1 = -1;
	}
}

void deleted(Man*& person, int& num) // удаление всех элементов с указанным ростом и весом
{
	system("chcp 1251>nul");
	int height1, weight1;
	cout << "Введите рост. ";
	cin >> height1;
	cout << "Введите вес. ";
	cin >> weight1;
	
	for (int i = 0; i < num; i++)
	{
		if (person[i].growth == height1 && person[i].weight == weight1) {
			for (int j = i; j < num; j++)
			{
					for (int k = j; k < num - 1; k++)
					{
						person[k].surname = person[k + 1].surname;
						person[k].name = person[k + 1].name;
						person[k].YOB = person[k + 1].YOB;
						person[k].growth = person[k + 1].growth;
						person[k].weight = person[k + 1].weight;
						
					}
					num--;
			}
		}
	}
}

void Vvod1(Man*& person0, int num, int k) // ввод данных для второго массива
{
	system("chcp 1251>nul");
	int  YOB1 = -1, growth1 = -1, weight1 = -1;
	for (int i = k; i < num; i++)
	{
		cout << endl;
		cout << "Введите ФИО \t";
		cin >> person0[i].surname;
		getline(cin, person0[i].name);
		cout << "Введите год рождения:\n";
		while ((YOB1 >= 2022 || YOB1 < 0))
		{
			cout << "Год рождения:\t";
			cin >> YOB1;
			if ((YOB1 >= 2022 || YOB1 < 0))
			{
				cout << "Введены некоректные данные!" << endl;
			}
			person0[i].YOB = YOB1;
		}
		while (person0[i].growth < 0)
		{
			cout << "Введите рост:\t";
			cin >> growth1;
			if (growth1 < 0)
			{
				cout << "Введены некоректные данные!" << endl;
			}
			person0[i].growth = growth1;
		}
		while (person0[i].weight < 0)
		{
			cout << "Введите вес:\t";
			cin >> weight1;
			if (weight1 < 0)
			{
				cout << "Введены некоректные данные!" << endl;
			}
			person0[i].weight = weight1;
		}
		YOB1 = -1;
		growth1 = -1;
		weight1 = -1;
	}
}

void added(Man*& person, Man*& person0, int& num) // добавление элемента после указанной фамилии
{
	bool k = false;
	string surname1;
	cout << endl << "Введите фамилию \t";
	cin >> surname1;
	for (int i = 0; i < num; i++)
	{
		if (person[i].surname == surname1)
		{
			k = true;
			for (int j = 0; j <= i; j++)
			{
				person0[j].surname = person[j].surname;
				person0[j].name = person[j].name;
				person0[j].YOB = person[j].YOB;
				person0[j].growth = person[j].growth;
				person0[j].weight = person[j].weight;
			}
			cout << "Введите новые параметры человека." << endl;

			Vvod1(person0, i + 2, i + 1);
			for (int j = i + 2; j <= num; j++)
			{
				person0[j] = person[j - 1];
			}

			i = num;
		}
	}
	if (k == false)
	{
		cout << "Введённой фамилии нет в списке." << endl;
	}
}

int main()
{
	system("chcp 1251>nul");

	int num = -1;
	while (num <= 0)
	{
		cout << "Введите количество людей. ";
		cin >> num;
	}
	cout << endl;
	Man* person = new Man[num];
	Man* person0 = new Man[num + 1];
	Vvod(person, num, 0);
	for (int i = 0; i < num; i++) {
		cout << endl;
		cout << person[i].surname;
		cout << person[i].name;
		cout << endl;
		cout << person[i].YOB;
		cout << endl;
		cout << person[i].growth;
		cout << endl;
		cout << person[i].weight;
		cout << endl;
		cout << endl;
	}
	deleted(person, num);
	for (int i = 0; i < num; i++) {
		cout << person[i].surname;
		cout << person[i].name;
		cout << endl;
		cout << person[i].YOB;
		cout << endl;
		cout << person[i].growth;
		cout << endl;
		cout << person[i].weight;
		cout << endl;
		cout << endl;
	}
	if (num != 0) {
		added(person, person0, num);
		for (int i = 0; i < num + 1; i++) {
			cout << person0[i].surname;
			cout << person0[i].name;
			cout << endl;
			cout << person0[i].YOB;
			cout << endl;
			cout << person0[i].growth;
			cout << endl;
			cout << person0[i].weight;
			cout << endl;
			cout << endl;
		}
	}
	else {
		cout << "Нет данных.";
		cout << endl;
	}

	return(0);
}