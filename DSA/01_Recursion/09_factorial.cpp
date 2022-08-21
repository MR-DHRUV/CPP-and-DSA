#include <iostream>
using namespace std;

int factorialCalc(int n)
{

    if (n > 0)
    {
        return factorialCalc(n - 1) * n;
    }

    else
    {
        return 1;
    }
}

int factorialCalcloop(int n)
{
    int fac = 1;

    if (n < 0)
    {
        return 1;
    }

    for (n; n > 0; n--)
    {
        fac = fac * n;
    }

    return fac;
}

int main()
{
    cout << factorialCalc(0) << endl;
    cout << factorialCalc(12) << endl;

    cout<<factorialCalcloop(0)<<endl;
    cout<<factorialCalcloop(-9)<<endl;
    cout<<factorialCalcloop(12)<<endl;
    return 0;
}