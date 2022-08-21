#include <iostream>
using namespace std;

// tailer series using horners rule
// faster then simple reccursive method

double e(int x, int n)
{
    static double s;

    if (n == 0)
    {
        return s;
    }

    else
    {
        s =  1+ (x*s/n);
        return e(x,n-1);
    }
}




double eLoop(int x , int n){

    double term = 1;

    for (n ;n >0; n--)
    {
        term = 1 +( term * x / n);
    }

    return term;

}



int main()
{
    cout << e(1, 100000)<<endl;
    cout << eLoop(1, 100000)<<endl;

    return 0;
}