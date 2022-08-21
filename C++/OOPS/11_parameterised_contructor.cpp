#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex(int x , int y); // declareation of constructor;

    void getValue(void)
    {
        cout << "The value of  a is " << a << " and b is " << b << endl;
    };
};

Complex ::Complex(int x , int y)// parameterized contructor
{
    a = x;
    b = y;
};

int main()
{
    // to set value there are two methods
    
    // 1 Implicit call
    Complex a(5,6);
    a.getValue();

    // 2 Explicit call
    Complex b = Complex(5,7);
    b.getValue();
    

    return 0;
}