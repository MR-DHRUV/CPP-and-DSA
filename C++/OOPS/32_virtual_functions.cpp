#include <iostream>
using namespace std;

class BaseClass
{
public:
    int base;
    virtual void display()
    {
        cout << "Base " << base;
    };
};

class DerivedClass : public BaseClass
{

public:
    int derived;
    void display()
    {
        cout << "Base " << base << endl;
        cout << "derived " << derived << endl;
    };
};

int main()
{
    // if we want a base class pointer pointing towards a derived class object to execute functions of derived class then we use virtual functions;
    // virtual functions runtime polymorphism show krte hain

    BaseClass *ptr_of_base;
    DerivedClass obj;

    ptr_of_base = &obj;
    // as base class display has been made virtual, now it will decide during runtime that will display will be called
    // directly base class ka display call nahi karega 
    ptr_of_base->display();

    return 0;
}