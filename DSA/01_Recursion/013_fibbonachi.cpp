#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int fibloop(int n){

    int t0 = 0;
    int t1 = 1;

    for (int i = 0; i < n; i++)
    {
        int temp = t1;
        t1 = t1+ t0;
        t0 = temp;
    }
    return t0;

}

int main()
{
    cout << fib(0) << endl;
    cout << fib(1) << endl;
    cout << fib(2) << endl;
    cout << fib(3) << endl;
    cout << fib(4) << endl;
    cout << fib(5) << endl;


    cout << fibloop(0) << endl;
    cout << fibloop(1) << endl;
    cout << fibloop(2) << endl;
    cout << fibloop(3) << endl;
    cout << fibloop(4) << endl;
    cout << fibloop(5) << endl;

    return 0;
}