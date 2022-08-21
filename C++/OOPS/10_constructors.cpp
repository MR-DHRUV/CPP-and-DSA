#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    // creating a constructor
    // it a special member function with same name as of the class
    // it is used to initailze the objects of the class
    // it has same name as of the class
    // it is automatically invoked
    // they cannot return the value
    // we cannot refer to their address

    Complex(void); // declareation of constructor;

    void getValue(void)
    {
        cout << "The value of  a is " << a << " and b is " << b << endl;
    };
};

Complex ::Complex(void)// iit ia default constructor thus, on initilaizing a object default values are assigned 
{
    a = 0;
    b = 0;
};

int main()
{
    Complex C;
    C.getValue();

    return 0;
}