#include <iostream>
#include "fraction.h"
using namespace std;

int  main()
{
	fraction B;
	B.Read();
	B.Show();
	cout << "����� � �������: " << B.minutes(B.first, B.second) << endl << endl;

	return 0;
}