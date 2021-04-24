
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define NMAX 10
using namespace std;

class stc
{
public:
	char elem[NMAX];
	int top;
};

int isempty(struct stc* st)
{
	if (st->top == 0)    return 1;
	else return 0;
}

void init(struct stc* st)
{
	st->top = 0;
}

void push(struct stc* st, char f)
{
	if (st->top < NMAX) {
		st->elem[st->top] = f;
		st->top++;
	}
	else
		cout << "Стек полон.";
}

void pushnew(struct stc* st, char f)
{
	char k;
	cout << "Введите новый элемент стека: ";
	cin >> k;
	if (st->top < NMAX) {
		for (int i = 0; i < st->top; i++)
		{
			if (st->elem[i] == f)
			{
				for (int j = (st->top) + 1; j > i + 1; j--)
				{
					st->elem[j] = st->elem[j - 1];
				}
				st->elem[i + 1] = k;
				st->top++;
				break;
			}
		}
	}
	else
		cout << "Стек полон.";
}


void Print(struct stc* stk)
{
	int i;
	i = stk->top;
	if (isempty(stk) == 1) return;
	do {
		i--;
		cout << stk->elem[i] << endl;
	} while (i > 0);
}


int main()
{
	setlocale(LC_ALL, "ru");

	struct stc* st;
	int n;
	char elem, f;

	st = (struct stc*)malloc(sizeof(struct stc));
	init(st);

	cout << "Введите количество элементов в стеке: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент: ";
		cin >> elem;
		push(st, elem);
	}
	Print(st);

	cout << "Введите элемент после которого хотите добавить новый: ";
	cin >> f;
	pushnew(st, f);
	Print(st);

	return(0);
}