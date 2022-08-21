#include <iostream>
using namespace std;

class A
{

    int a;

public:
    // returns an error
    // void setdata(int a)
    // {
    //     a = a;
    // };

    // using this to target a of class
    // this keyword points to class
    // void setdata(int a)
    // {
    //     this->a = a;
    // };


    // returns an object of class A
    // using this syntax will make setdata point to that object of this class
    A & setdata(int a)
    {
        this->a = a;
        return *this;
    };

    void getData()
    {
        cout << a << endl;
    };
};

int main()
{
    // A a;
    // a.setdata(4);
    // a.getData();

    A a;
    a.setdata(4).getData();

    return 0;
}