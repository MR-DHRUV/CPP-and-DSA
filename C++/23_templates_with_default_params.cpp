#include <iostream>
using namespace std;

// default params
template <class T1 =int, class T2 = int>

class myClass
{

public:
    T1 data1;
    T2 data2;

    myClass(T1 a, T2 b) : data1(a), data2(b)
    {
        cout << "Data set" << endl;
    }

    void display()
    {
        cout << this->data1 << endl
             << this->data2 << endl;
    };
};


int main()
{
    // emplty angular brackets ka matlab haii no arguments are gieven souse default params; 
    myClass <> obj(1,1);
    obj.display();

    myClass<float, float> obj1(1.99,1.1);
    obj1.display();


    return 0;
}
