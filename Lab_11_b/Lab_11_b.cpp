
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
	lab* p, *p1, *p2;
	int h = 0;

	p = head;				
	p1 = head;
	p2 = head;

	for (int i = 1; i <= size; i++)
	{
		if ((p->data) % 2 == 0)
		{
			if (p->next == NULL)
			{

				delete p;
				p = p1; p2 = p1;
				p1->next = NULL;
				break;

			}
			p2 = p->next;
			delete p;
			p1->next = p2;
			p1 = p2;
			p = p2;
		}
			else {

				if (p2->next == NULL)
					break;

				p = p->next;
				p2 = p->next;

			}
		

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


	delete head;
	return(0);
}

