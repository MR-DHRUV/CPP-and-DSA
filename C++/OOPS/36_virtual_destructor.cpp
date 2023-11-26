#include <iostream>

class Base
{
public:
    // Virtual destructor
    virtual ~Base()
    {
        std::cout << "Base Destructor" << std::endl;
    }

    // Virtual function
    virtual void someFunction()
    {
        std::cout << "Base someFunction" << std::endl;
    }
};

class Derived : public Base
{
public:
    // Destructor (implicitly virtual since it overrides a virtual function)
    ~Derived() override
    {
        std::cout << "Derived Destructor" << std::endl;
    }

    // Overridden virtual function
    void someFunction() override
    {
        std::cout << "Derived someFunction" << std::endl;
    }
};

int main()
{
    // Using polymorphism with a pointer to the base class
    Base *basePtr = new Derived;

    // Calling a virtual function
    basePtr->someFunction();

    // Deleting through a pointer to the base class
    delete basePtr;

    return 0;
}
