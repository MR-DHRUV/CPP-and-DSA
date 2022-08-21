#include <iostream>
using namespace std;

int sum(int a, int b)
{
    return a + b;
}

void swapi(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
};

void swapVar(int &b, int &a)
{
    int temp = a;
    a = b;
    b = temp;
};

int main()
{
    int a = 2, b = 3;

    // call by value
    int c = sum(a, b);
    cout << c << endl;

    int *e = &a;
    int *d = &b;

    // call by refrence
    swapi(e, d);
    cout << a << endl
         << b << endl;

    // better solution
    swapVar(a, b);
    cout << a << endl
         << b << endl;

    return 0;
}
