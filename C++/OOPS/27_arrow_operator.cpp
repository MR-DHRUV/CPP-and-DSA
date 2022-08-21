#include <iostream>
using namespace std;

class Complex
{
    int real, imaginary;

public:
    void getData()
    {
        cout << "The real part is " << real << endl;
        cout << "The imaginary part is " << imaginary << endl;
    }
    Complex(int a, int b) : real(a), imaginary(b)
    {
        cout << "Data set" << endl;
    };
};

int main()
{
    Complex c1(2,3);
    c1.getData();

    // same as integer pointer bas iska bata type Complex haii
    Complex *ptr =&c1;

    //normal syntax
    (*ptr).getData();

    // arrow syntax
    ptr->getData();



    Complex *ptr1 = new Complex(10,20);
    ptr1->getData();


    // Complex *ptrArr = new Complex[4];
    

    return 0;
}