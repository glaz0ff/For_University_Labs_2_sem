
#include <iostream>
using namespace std;

int queen[8];

bool kroet(int gor, int vert, int a, int b)
{
    return (vert == b) || (gor - a == vert - b) || (gor - a == b - vert) || (gor == a);
}

bool proverka(int a, int b)
{
    for (int n = 0; n < a; n++) {
        if (kroet(n, queen[n], a, b))
        {
            return false;
        }
    }
    return true;
}

void print()
{
    for (int a = 7; a > -1; a--)
    {
        for (int b = 0; b < 8; b++)
        {
            if (b == 0)
                cout << "| ";

            if (b == queen[a])
            {
                cout << "Q ";
            }

            cout << "0 ";
        }

        cout << endl;
    }
}

void ferz()
{
    int num = 1;
    for (int a = 0; a < 8; ++a)
    {
        queen[0] = a;
        for (int b = 0; b < 8; ++b)
            if (proverka(1, b))
            {
                queen[1] = b;
                for (int c = 0; c < 8; ++c)
                    if (proverka(2, c))
                    {
                        queen[2] = c;
                        for (int d = 0; d < 8; ++d)
                            if (proverka(3, d))
                            {
                                queen[3] = d;
                                for (int e = 0; e < 8; ++e)
                                    if (proverka(4, e))
                                    {
                                        queen[4] = e;
                                        for (int f = 0; f < 8; ++f)
                                            if (proverka(5, f))
                                            {
                                                queen[5] = f;
                                                for (int g = 0; g < 8; ++g)
                                                    if (proverka(6, g))
                                                    {
                                                        queen[6] = g;
                                                        for (int h = 0; h < 8; ++h)
                                                            if (proverka(7, h))
                                                            {
                                                                queen[7] = h;

                                                                cout << endl << endl << num++ << ": " << endl;
                                                                print();
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
    }
}

int main()
{
    ferz();
    cout << endl;

    return 0;
}
