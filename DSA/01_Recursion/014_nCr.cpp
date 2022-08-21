#include <iostream>
using namespace std;

double recPart(int diffrence, int nn)
{
    static int num = 1;
    static int den = 1;

    num = num * nn;
    den = den * diffrence;

    if (diffrence <= 1)
    {

        return (num / den);
    }

    return recPart(diffrence - 1, nn - 1);
}

double nCr(int n, int r)
{
    int n_r = n - r;

    if(n_r <= 0){
        return 1;
    }

    return recPart(n_r, n);
}

int main()
{
    cout << nCr(10, 5);
    return 0;
    
}