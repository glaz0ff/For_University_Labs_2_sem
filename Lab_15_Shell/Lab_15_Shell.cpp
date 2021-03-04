
#include <iostream>
using namespace std;

struct book
{
	string name;
	int num;
};

void shell(book* arr, int n)
{
	int i, j, d, ll;
	string pp;
	d = n;
	d = d / 2;
	while (d > 0)
	{
		for (i = 0; i < n - d; i++)
		{
			j = i;
			while (j >= 0 && arr[j].num > arr[j + d].num)
			{
				ll = arr[j].num;
				arr[j].num = arr[j + d].num;
				arr[j + d].num = ll;
				pp = arr[j].name;
				arr[j].name = arr[j + d].name;
				arr[j + d].name = pp;
				j--;
			}
		}
		d = d / 2;
	}
}


int main()
{
	setlocale(LC_ALL, "ru");

	int n = -1;

	cout << "Введите колличество книг: ";
	while (n <= 0)
	{
		cin >> n;
		cout << endl;
		if (n < 0)
		{
			cout << "Неверный ввод." << endl;
		}
	}

	book* bk = new book[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Введите название книги: ";
		cin >> bk[i].name;
		cout << "Введите колличество страниц книги: ";
		cin >> bk[i].num;
	}
	cout << endl;
	cout << "Список книг до сортировки: " << endl << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Название " << i + 1 << "книги: " << bk[i].name;
		cout << endl;
		cout << "Колличество страниц " << i + 1 << "книги: " << bk[i].num;
		cout << endl;
	}
	cout << endl;

	shell(bk, n);

	cout << "Список книг после сортировки: " << endl << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Название " << i + 1 << "книги: " << bk[i].name;
		cout << endl;
		cout << "Колличество страниц " << i + 1 << "книги: " << bk[i].num;
		cout << endl;
	}
	cout << endl;

	return(0);
}


