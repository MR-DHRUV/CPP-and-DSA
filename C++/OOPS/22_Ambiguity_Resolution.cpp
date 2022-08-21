#include <iostream>
using namespace std;

class Base1
{
public:
    void Greet()
    {
        cout << "Good Morning" << endl;
    };
};

class Base2
{
public:
    void Greet()
    {
        cout << "Good Night" << endl;
    };
};

class Derived : public Base1, public Base2
{
    int a;

    //Resolving ambiquity
    public:
    void Greet(){
        Base1  :: Greet(); 
    };

    //Method 2

    // void Greet(){
    //     cout<<"Another method"<<endl;
    // }


};

int main()
{
    Base1 base1obj;
    Base2 base2obj;
    Derived ambhiquityObj;
     
    base1obj.Greet(); 
    base2obj.Greet(); 

    ambhiquityObj.Greet();


    return 0;
}