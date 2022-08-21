#include <iostream>
using namespace std;

// forward declareation
class Y;

class X
{
    int data;
    friend void add(X o1, Y o2);
    friend void swap(X &o1, Y &o2);

public:
    void setValue(int a)
    {
        data = a;
    };
    void getValue(void)
    {
        cout << "The value of object of class X is " <<data<< endl;
    };
};

class Y
{
    int num;
    friend void add(X o1, Y o2);
    friend void swap(X &o1, Y &o2);

public:
    void setValue(int a)
    {
        num = a;
    };
    void getValue(void)
    {
        cout << "The value of object of class Y is " << num << endl;
    };
};

void add(X o1, Y o2)
{
    cout << "The result is " << (o1.data + o2.num) << endl;
};

void swap(X &o1, Y &o2)
{
    int tempVar;
    tempVar = o2.num;
    o2.num = o1.data;
    o1.data = tempVar;
}

main()
{
    X a;
    Y b;
    a.setValue(3);
    b.setValue(2);

    add(a, b);

    a.getValue();
    b.getValue();
  
    swap(a, b);

    a.getValue();
    b.getValue();
    

    return 0;
}