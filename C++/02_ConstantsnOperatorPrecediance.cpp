#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int a =34;
    a = 45;
    const int b = 3;
    // b = 900; returns a error 
    cout<<a<<endl;
    cout<<b<<endl;
    
    // Manipulators
    // wo operators jo data display ko format krte hain
    // endl is a manipulator

    int c = 9;
    cout<<"The value of a is "<<a<<endl;
    cout<<"The value of b is "<<b<<endl;
    cout<<"The value of c is "<<c<<endl;

    //setw width deta haii kisi bhi cheej ko
    cout<<"The value of a is "<<setw(4)<<a<<endl;
    cout<<"The value of b is "<<setw(4)<<b<<endl;
    cout<<"The value of c is "<<setw(4)<<c<<endl;
    
    /////////////// Operator precedence ////////////////

    int calc = a*5+c/b;
    int calc1 = ((a*5)+c)/b;

    cout<<calc<<endl;
    cout<<calc1<<endl;

    //they have differert value as when not secified with brackets, compiler starts calculating with operator with highest precedence 









    return 0;
}