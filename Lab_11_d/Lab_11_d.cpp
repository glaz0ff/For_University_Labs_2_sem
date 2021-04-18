
#include <iostream>
#define PMAX 100
using namespace std;

struct queue
{
    int qu[PMAX];
    int rear, frnt;
};

void init(struct queue* q)
{
    q->frnt = 1;
    q->rear = 0;
    return;
}

void vvod(struct queue* q, int x) 
 {
    if (q->rear < PMAX - 1)
    {
        q->rear++;
        q->qu[q->rear] = x;
    }
    else
        cout << "ќчередь полна" << endl;
    return;
}

int isempty(struct queue* q)
{
    if (q->rear < q->frnt)    return 1;
    else  return 0;
}

void print(struct queue* q) 
{
    int h;
    if (isempty(q) == 1)
    {
        cout << "ќчередь пуста." << endl;
        return;
    }
    for (h = q->frnt; h <= q->rear; h++)
        cout << q->qu[h];
    return;
}

int main()
{
    setlocale(LC_ALL, "ru");

    int n, k;
    struct queue* q;
    q = (queue*)malloc(sizeof(queue));

    init(q);

    cout << "¬ведите колличество элементов очереди: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "¬ведите новый элемент: ";
        cin >> k;
        vvod(q, k);
    }
    print(q);

    for (int j = 0; j < n; j++)
    {
            if (q->qu[j] % 2 == 0)
            {
                for (int o = j; o < n+1; o++)
                {
                    q->qu[o] = q->qu[o + 1];
                }
                q->rear--;
            }
    }
    cout << endl << endl;
    print(q);
    return(0);
}

