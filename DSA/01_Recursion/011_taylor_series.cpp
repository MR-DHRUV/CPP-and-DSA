#include <iostream>
using namespace std;

//    x
/// e    till n

// factorial

// 1 x/1  x2/2! x3/3!

double e(int x, int n)
{

    static double p = 1, f = 1;
    double r;

    if (n == 0)
    {
        return 1;
    }
    else
    {
        r = e(x, n - 1);
        p = p * x;
        f = f * n;

        return r + p / f;
    }
};

double eLoop(int x, int n)
{

    double sum = 1; 
    double num = 1 , den = 1; 

    for (int i = 1; i <= n; i++)
    {
        num = num *x;
        den = den * i;

        sum = sum + (num / den);
    }

    return sum;
    
}

int main()
{
    cout << e(4, 500)<<endl;
    cout << eLoop(4, 500)<<endl;
    return 0;
}

// no multiplactions in each step 2
// no multiplactions in 4 steps