#include <iostream>
using namespace std;

// if both base and derived class have constructors with arguments then constructor of base class is called first;

// multiple inheritance me jis order me likha haii  uss order me execute hoga

// base -> virtual -> non virtual

// constructors of virtual base class are invoked before non virtual class but after base class;
// if multiple virtual base class are there then their contructors will be invoked in the order of declareation

/*
Case1:
class B: public A{
   // Order of execution of constructor -> first A() then B()
};

Case2:
class A: public B, public C{
    // Order of execution of constructor -> B() then C() and A()
};

Case3:
class A: public B, virtual public C{
    // Order of execution of constructor -> C() then B() and A()
};

*/

class Base1
{
    int data1;

public:
    Base1(int a)
    {
        data1 = a;
        cout << "Base1 class constructor called" << endl;
    };
    void printData1()
    {
        cout << "The data is " << data1 << endl;
    }
};

class Base2
{
    int data2;

public:
    Base2(int a)
    {
        data2 = a;
        cout << "Base2 class constructor called" << endl;
    };
    void printData2()
    {
        cout << "The data is " << data2 << endl;
    }
};

// constructor uska pahle run hoga jo yaha pahle likha hoga
class Derived : public Base1, public Base2
{
    int derived1, derived2;

public:
    // this will give a to base1 constructor and b to base2 constructor
    Derived(int a, int b, int c, int d) : Base2(a), Base1(b)
    {
        derived1 = c;
        derived2 = d;
        cout << "Derived class constructor called" << endl;
    }
    void printData()
    {
        cout << "The derived1 is " << derived1 << endl;
        cout << "The derived2 is " << derived2 << endl;
    }
};

int main()
{
    Derived Harry(1, 2, 3, 4);
    Harry.printData();
    return 0;
}