#include <iostream>
using namespace std;

class BaseClass
{
public:
    int base;
    void display()
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
        cout << "Base " << base;
        cout << "derived " << derived;
    };
};

int main()
{
    BaseClass objBase;
    BaseClass *base_class_pointer;

    DerivedClass objDerived;

    // it will not throw error as base class pointer can point to derived class derived from that base class;
    base_class_pointer = &objDerived;

    base_class_pointer->base = 34;

    // it is a runtime decission that which display will be called, thus it is called runtime polymorphism
    // it is running display of base class as it is a pointer of base class and it is binded with base class
    base_class_pointer->display();

    // cannot be accessed as there is no member named derived in base class
    // base_class_pointer.derived;

    // You cannot point derived class pointer to base class
    // BaseClass MYbASE;
    // DerivedClass *derived_class_pointer;
    // derived_class_pointer = &MYbASE;

    return 0;
}