#include <iostream>
using namespace std;

class Base
{
    int data1; // private by default and is not inheritable

public:
    int data2; // inhertable
    void setData();
    int getData1();
    int getData2();
};

void Base ::setData()
{
    data1 = 10;
    data2 = 20;
};

int Base ::getData1()
{
    return data1;
};

int Base ::getData2()
{
    return data2;
};

class Derived : Base
{
    int data3;

public:
    void process();
    void display();
    void init();
};

void Derived ::process()
{
    data3 = data2 * (getData1());
};

void Derived ::display()
{
    cout << "The value of data 1 is " << getData1() << endl; // prive thus function needs to be called
    cout << "The value of data 2 is " << data2 << endl;
    cout << "The value of data 3 is " << data3 << endl;
};


// to make code work for private inheriatnce
void Derived ::init()
{
    setData();
};


int main()
{
    Derived der;
    // der.setData(); this will be called when inheritation is public

    der.init(); // this will be called when inheritation is private
    der.process();
    der.display();

    return 0;
}