#include<iostream>
using namespace std;

inline int multiply(int a, int b){
    return a*b;
};

int product(int a){
    static int c = 0;
    c++;
    return c*a;

} 
//only small functions that will be called multiple times during execution of a program are needed to be made inline.

//default arguments and constant arguments 

double accBalance(const int currentMoney, double factor = 1.04){
    return currentMoney*factor;
}
// here 1.04 is the default arg and current money is made constant so that function accidently dont change it

int main()
{
    int a, b;
    cout<<"Enter the value of a and b"<<endl;
    cin>>a>>b;
    cout<<"THe product is "<<multiply(a,b)<<endl;
    cout<<"THe product with static variabele is : "<<product(a)<<endl;
    cout<<"THe product with static variabele is : "<<product(a)<<endl;

    // cout<<"THe product with static variabele is : "<<product(a)<<endl;
    // cout<<"THe product with static variabele is : "<<product(a)<<endl;
    // cout<<"THe product with static variabele is : "<<product(a)<<endl;
    // cout<<"THe product with static variabele is : "<<product(a)<<endl;
    // cout<<"THe product with static variabele is : "<<product(a)<<endl;
    // cout<<"THe product with static variabele is : "<<product(a)<<endl;
    // cout<<"THe product with static variabele is : "<<product(a)<<endl;

    cout<<"The money with oridinary person is : "<<accBalance(50000)<<endl;
    cout<<"The money with vip person is : "<<accBalance(50000,1.10)<<endl;

    return 0;
} 
