#include <iostream>
using namespace std;

// constructor (argument-list) : initialization-section
//{
// code here
//}

class Test
{
    int a, b;

public:
    // argument list
    // Test(int i, int j) : a(i), b(i+j) // run
    // Test(int i, int j) : a(i+b), b(i) // not run as a is declared before b so it will be initialised first
    Test(int i, int j) : a(i), b(i+a)  //run
    {
        cout << "Constuctor called" << endl;
        cout << a << endl;
        cout << b << endl;
    };
};

int main()
{
    Test a(1, 2);

    return 0;
}