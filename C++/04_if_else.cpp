#include<iostream>
using namespace std;

int main()
{
    int age;
    cout<<"Enter your age : ";
    cin>>age;

    if(age>=18){
        cout<<"You can come to the party"<<endl;
    }
    else if(age>=16 && age<18){
        cout<<"You can come to the party with a kid pass"<<endl;
    }
    else{
        cout<<"You cant come to the party";
    }



    return 0;
}