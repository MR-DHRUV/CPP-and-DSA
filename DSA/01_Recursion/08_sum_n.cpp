#include <iostream>
using namespace std;

void sumN(int n)
{

    static int sum = 0;

    if (n > 0)
    {
        sum = sum + n;
        return sumN(n - 1);
    }

    cout << sum<<endl;
}

void sumNLoop(int n){

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout<<sum<<endl;
    
}

int main()
{
    sumN(100);
    sumNLoop(100);
    return 0;
}