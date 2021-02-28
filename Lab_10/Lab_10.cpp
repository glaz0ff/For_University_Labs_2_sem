
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int n, k, i, j, num, kol;
	int l;

	cout << "Введите колличество элементов массива: ";
	cin >> n;
	cout << endl;
	int* arr = new int[n];

	for (i = 0; i < n; i++) {
		arr[i] = 1 + rand() % INT_MAX;
	}
	for (i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << endl;

	cout << "Укажите элемент, с которого начнется удаление: ";
	cin >> num;
	cout << endl;
	cout << "Укажите колличество элементов, которое хотите удалить: ";
	cin >> k;
	cout << endl;
	for (i = 0; i < n; i++) {
		for (kol = i; kol < n; kol++) {
			if (i == num - 1) {
				for (l = i; l < k + i; l++) {
					for (j = i; j < n; j++) {
						arr[j] = arr[j + 1];
					}
					n--;
				}
				break;
			}
		}
	}
	for (i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	k = 0;
	num = 0;
	cout << endl;
	cout << endl;

	cout << "Укажите элемент, с которого начнется добавление: ";
	cin >> num;
	cout << endl;
	cout << "Укажите колличество элементов, которое хотите добавить: ";
	cin >> k;
	cout << endl;

	int* arr1 = new int[k + n];
	arr1 = arr;

	for (i = 0; i < n + k; i++) {
		for (kol = i; kol < n + k; kol++) {
			if (i == num) {
				for (l = i; l < k + i; l++) {
					for (j = n + k; j > l; j--) {
						arr1[j] = arr1[j - 1];
					}
					cin >> arr1[l];
				}
				break;
			}
		}
	}
	for (i = 0; i < n + k; i++) {
		cout << arr1[i] << " ";
	}

	return(0);
}