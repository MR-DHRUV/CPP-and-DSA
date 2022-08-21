#include <iostream>
using namespace std;

// syntax for multiple inheritance
//         A1 ....... An
//               C

// class Derived  : visibility-mode class-1, visibility-mode class2{
//
//}

class Base1
{
protected:
    int base1int;

public:
    void set_base1int(int i)
    {
        base1int = i;
    }
};



class Base2
{
protected:
    int base2int;

public:
    void set_base2int(int i)
    {
        base2int = i;
    }
};



class Derived : public Base1, public Base2
{
public:
    void show()
    {
        cout << "The value of base1 is " << base1int << endl;
        cout << "The value of base2 is " << base2int << endl;
        cout << "The sum is is " << (base2int + base1int) << endl;
    }
};


int main()
{

    Derived A;
    A.set_base1int(3);
    A.set_base2int(3);
    A.show();



    return 0;
}