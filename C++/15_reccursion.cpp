#include <iostream>
using namespace std;

int factorial(int a);
int fibonacchi(int a);

int main()
{
    cout << factorial(9) << endl;
    cout << factorial(10) << endl;
    cout << factorial(8) << endl;
    cout << factorial(1) << endl;
    cout << factorial(2) << endl;
    cout << factorial(3) << endl;
    cout << factorial(0) << endl;
    
    cout<<endl<<endl;

    cout<<fibonacchi(0)<<endl;
    cout<<fibonacchi(1)<<endl;
    cout<<fibonacchi(2)<<endl;
    cout<<fibonacchi(3)<<endl;
    cout<<fibonacchi(4)<<endl;
    cout<<fibonacchi(5)<<endl;
    cout<<fibonacchi(6)<<endl;
    cout<<fibonacchi(7)<<endl;


    return 0;
}

int factorial(int a)
{
    if (a > 1)
    {
        return a * (factorial(a - 1));
    }
    else if (a == 1)
    {
        return 1;
    }
    else if (a <= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int fibonacchi(int a)
{
    if (a > 1)
    {
        return fibonacchi(a - 1) + fibonacchi(a - 2);
    }
    else if (a == 1)
    {
        return 1;
    }
    else if (a == 0)
    {
        return 0;
    }
    else
    {
        return 0;
    }
}
