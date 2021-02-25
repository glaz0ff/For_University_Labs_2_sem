
#include <iostream>
#include <string>

using namespace std;

struct lab
{
	int data;
	lab* next;
	lab* prev;
};


lab* vvod(int size)
{
	lab* p = new lab;
	lab* head = new lab;
	head = NULL;
	cout << "Введите первый элемент списка: ";
	cin >> p->data;
	head = p;
	p->next = NULL;
	p->prev = NULL;

	for (int i = 2; i <= size; i++)
	{
		lab* r = new lab;
		lab* u = p;
		p->next = r;
		p = p->next;
		cout << "Введите элемент списка: ";
		cin >> p->data;
		p->next = NULL;
		p->prev = u;

	}

	return head;
}

void de(lab* head, int size)
{
	lab* p = head;
	int h = 0;

	
		for (int i = 0; i < size; i++)
		{

			if ((head->data) % 2 == 0)
			{
				head = head->next;
				h++;
				p = head;
				p->prev->next = head->next;
				p->next->prev = head->prev;
				delete p;

			}
			else
			{
				head = head->next;
			}

		}
	size -= h;
	
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

//void clean(lab* head) {
//	lab* elem = head;
//	elem = head;
//	head = head->next;
//	delete elem;
//}


int main()
{
	setlocale(LC_ALL, "ru");
	int size = -1, n = 0;
	cout << "Введите кол-во элементов списка: ";
	while (size <= 0)
	{
		cin >> size;

		if (size <= 0)
			cout << "Неверный ввод.";
	}

	lab* head = vvod(size);

	print(head);
	cout << endl;

	de(head, size);
	print(head);
	cout << endl;

	//clean(head);
	delete head;
	return(0);
}

