//���������
//����. � - double
//����. B - double
//����. C - double
#include "Yravnenie.h"
#include <iostream>
using namespace std;

yravnenie make_yravnenie()
{
	double a1;
	double b1;
	double c1;
	cout << "������� ���������� �:" << endl;
	cin >> a1;
	cout << "������� ���������� B:" << endl;
	cin >> b1;
	cout << "������� ���������� C:" << endl;
	cin >> c1;
	yravnenie t(a1, b1, c1);
	return t;
}

void print_yravnenie(yravnenie t)
{
	t.show();
}

void main()
{
	setlocale(LC_ALL, "ru");
	yravnenie t1;
	t1.show();

	yravnenie t2(1, 2, 3);
	t2.show();

	yravnenie t3 = t2;
	t3.set_A(4);
	t3.set_B(5);
	t3.set_C(6);
	print_yravnenie(t3);

	t1 = make_yravnenie();
	t1.show();
}

