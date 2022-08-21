#include<iostream>
using namespace std;

int main()
{
    int a = 3;
    int *ptr = &a;
    int **ptrToPtr = &ptr;
    
    // & is called address of  operator
    cout<<**ptrToPtr<<endl; // * is called derefrencing operator
    cout<<*ptr<<endl; // * is called derefrencing operator
    cout<<a<<endl;    
    cout<<ptr<<endl;
    cout<<*ptrToPtr<<endl;
    cout<<ptrToPtr<<endl;





    return 0;
}