

#include <iostream>
using namespace std;



struct book 
{
    string name;
    int num;
};

void sort(book* arr, int first, int last)
{
	int k;
	string nm;
	int i = first;
	int j = last;

	while (i <= j)
	{
		while (arr[i].num < arr[(first + last) / 2].num && i < last)
		{
			i++;
		}
		while (arr[j].num > arr[(first + last) / 2].num && j > first)
		{
			j--;
		}

		if (i <= j)
		{
			k = arr[i].num;
			arr[i].num = arr[j].num;
			arr[j].num = k;
			nm = arr[i].name;
			arr[i].name = arr[j].name;
			arr[j].name = nm;
			i++;
			j--;
		}
		if (i < last)
		{
			sort(arr, i, last);
		}
		if (j > first)
		{
			sort(arr, first, j);
		}
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

	sort(bk, 0, n - 1);

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


