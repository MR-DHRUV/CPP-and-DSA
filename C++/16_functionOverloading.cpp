#include<iostream>
using namespace std;

int sum(int a, int b){
    cout<<"Function with 2 arguments"<<endl;
    return a+b;
}

int sum(int a, int b, int c){
    cout<<"Func with 3 arg"<<endl;
    return a+b+c;
}

int sum(int a, int b, int c, int d){
    cout<<"Func with 4 arg"<<endl;
    return a+b+c+d;
}
int sum(int a, int b, int c, int d, int e){
    cout<<"Func with 5 arg"<<endl;
    return a+b+c+d+e;
}



int main()
{
    cout<<"The sum is "<< sum(2,3,4,5,6) <<endl;
    cout<<"The sum is "<< sum(2,3,4,5) <<endl;
    cout<<"The sum is "<< sum(2,3,4) <<endl;
    cout<<"The sum is "<< sum(2,3) <<endl; 
    
    return 0;
}