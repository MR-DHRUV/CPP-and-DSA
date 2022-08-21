#include<iostream>
#include<string.h>

using namespace std;

// one can create class members like that
// class emplyoee{
//     class definition here
// } harry , dhruv ..... ;



class Employee{
    private:
        int a,b,c;
    public:
        int p,q,r;
        void setdData(int a1,int b1,int c1);
        void getData(){
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
            cout<<"The value of c is "<<c<<endl;
            cout<<"The value of p is "<<p<<endl;
            cout<<"The value of q is "<<q<<endl;
            cout<<"The value of r is "<<r<<endl;
        };
};

// :: is scope resolution operator
void Employee :: setdData(int a1,int b1,int c1){
    a = a1;
    b = b1;
    c = c1;
}
// members of private class can be only accessed by a function in a public class

int main()
{   
    Employee Harry;
    Harry.setdData(1,2,3);
    Harry.p = 3;
    Harry.q = 5;
    Harry.r = 7;
    Harry.getData();
    
    
    return 0;
}
