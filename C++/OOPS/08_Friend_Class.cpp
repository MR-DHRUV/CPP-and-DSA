#include <iostream>
using namespace std;


//forward declareation
class Complex; // assures that complex is present in the program to comiler


class Calculator
{
public:
    int sum(int a, int b)
    {
        return a + b;
    };

    int sumRealComlex(Complex r, Complex s);
    int sumImaginaryComlex(Complex r, Complex s);
};


class Complex
{
    int a;
    int b;
    // friend int Calculator ::sumRealComlex(Complex r, Complex s);
    // friend int Calculator ::sumImaginaryComlex(Complex r, Complex s);


    //Making whole class friend
    friend class Calculator;

    // returns error

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
};


// idhar isliye place kiya taaki comiler ko pata lagjaye ki complex ke ander a uar b hain
int Calculator :: sumRealComlex(Complex r, Complex s)
{
    return r.a + s.a;
};
int Calculator :: sumImaginaryComlex(Complex r, Complex s)
{
    return r.b + s.b;
};



int main()
{   
    Complex o1,o2,o3;

    o1.setData(2,3);
    o2.setData(41,35);
    
    Calculator calc;
    
    cout<<"The real sum is "<<calc.sumRealComlex(o1,o2)<<endl;
    cout<<"The imaginary sum is "<<calc.sumImaginaryComlex(o1,o2)<<endl;

    return 0;
}
