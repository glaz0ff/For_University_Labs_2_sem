#include "Vector.h"
#include "Time.h"
#include <iostream>
using namespace std;
void main()
{
	
	Vector<int>A(5, 0);
	cin >> A;
	cout << A << endl;
	Vector <int>B(10, 1);
	cout << B << endl;
	B = A;
	cout << B << endl;
	cout << A[2] << endl;
	cout << "size=" << A() << endl;
	B = A + 10;
	cout << B << endl;
	A = A * B;
	cout << A << endl;


	Time t;
	cin >> t;
	cout << t;

	int k;
	cout << "k?";
	cin >> k;
	Time p;
	cin >> p;
	p = t + p;
	cout << p;

	Vector<Time>A(5, t);
	cin >> A;
	cout << A << endl;
	Vector <Time>B(10, t);
	cout << B << endl;
	B = A;
	cout << B << endl;
	cout << A[2] << endl;
	cout << "size=" << A() << endl;
	A = A * B;
	cout << A << endl;
}


/*

�����- ��������� ������ � ���������� ���� int.
����������� �������� :
[] � ������� �� �������;
int() � ����������� ������� �������;
*������ � ��������� ��������� �������� a[i] * b[i];

���������������� ����� Time ��� ������ � ���������� �����������.��������
������ ���� ����������� � ���� ���� ����� : ������ ���� int � ������� ���� int.��� ������ ������ ���������� �� ������ ����������.

*/

