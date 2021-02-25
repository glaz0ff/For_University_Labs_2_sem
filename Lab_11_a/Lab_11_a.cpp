
#include <iostream>

using namespace std;

struct lab
{
	int num;
	char data;
	lab* next;
};

void vvod(int size, lab** head)
{
	if (size > 0) {
		(*head) = new lab;
		cout << "Введите элемент списка: ";
		cin >> (*head)->data;
		(*head)->next = NULL;
		vvod(size - 1, &((*head)->next));
	}
}

void dob(int D, lab* head)
{
	lab* p = head;
	lab* n = new lab;
	lab* l = new lab;
	while (p != 0)
	{
		if (p->data == D) {
			lab* o = new lab;
			n = p->next;
			p->next = o;
			p = p->next;
			cout << "Введите новый элемент: ";
			cin >> p->data;
			p->next = n;
		}
		p = p->next;
	}
}

void print(lab* head)
{
	if (head == NULL)
	{
		cout << "Список пуст.";
		cout << endl;
	}
	else {
		lab* p = head;
		while (p != 0)
		{
			cout << p->data << "\t";
			p = p->next;
		}
		cout << endl;
	}
	cout << endl;
}

void clean(lab* head) {
	lab* elem = head;
	elem = head;
	head = head->next;
	delete elem;
}


int main()
{
	setlocale(LC_ALL, "ru");
	int size = -1, n = 0;
	char D;
	cout << "Введите кол-во элементов списка: ";
	while (size <= 0)
	{
		cin >> size;

		if (size <= 0)
			cout << "Неверный ввод.";
	}
	lab* head;

	vvod(size, &head);
	print(head);
	cout << endl;

	cout << "Укажите элемент, после которого хотите добавить новый: ";
	cin >> D;
	cout << endl;

	dob(D, head);
	print(head);
	cout << endl;

	clean(head);

	return(0);
}

