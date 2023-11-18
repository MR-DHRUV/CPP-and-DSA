#include <iostream>
using namespace std;

class Number
{
    int a;

public:
    Number(){a=0;};

    Number(int num)
    {
        a = num;
    };

    // copy constructor
    // important: reference se hi lena padega as agar refer nahi kia toh ek copy contructor call hoga object ki copy bnane ke lie, ab uski copy ke kie ek aur baar hoga .. aise infinite loop of copy contructor me chale jayga. 
    Number(Number &num)
    {
        cout<<"Copy constructor called"<<endl;
        a = num.a;
    };


    void display()
    {
        cout << "The no of this object is " << a << endl;
    }
};

int main()
{
    Number x, y, z(45);

    x.display();
    z.display();

    // suppose i have to make z1 which is exacty like z
    // toh iske liye copy- constructor bnana padega

    
    Number z1(z) , z2;
    z1.display();
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // it runns without copy constructor as a default copy constructor is allocated to every class by compiler and it is used until a custom copy constructor is made;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    // basic jaise int =int krte ho aise hi same class = same class bhi ho jayga but in this case copy constructior will not be called;
    z2 = z;
    z2.display();


    // copy constructor call hoga as abhi declare hua h aur tabhi value dedi h usse
    Number z3 = z;
    z3.display();

    return 0;
}