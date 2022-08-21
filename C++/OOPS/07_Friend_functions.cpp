#include <iostream>
using namespace std;

class complex
{
    int a;
    int b;

public:
    void setData(int v1, int v2)
    {
        a = v1;
        b = v2;
    };

    void getData(void)
    {
        cout << "Your complex no is " << a << " + i " << b << endl;
    }
    friend complex sum(complex a1, complex b1);
};

// friend function
complex sum(complex a1 , complex b1){
    complex o3;
    o3.setData(a1.a + b1.a, a1.b+b1.b);
    return o3;
}


int main()
{
    complex c1, c2, c3;

    c1.setData(2, 4);
    c2.setData(3, 7);

    c3 = sum(c1,c2);
    c3.getData();

    return 0;
}

// Properties of a friend function 
// It is not in the scope of the class
// Since it is not in the scope of the class, it cannot be called like this c3.sum()
// contains objects as arguments
// can be written in both public or private section of the class
// it cannot access any member directly , it needs a derefrencing object to do that. 