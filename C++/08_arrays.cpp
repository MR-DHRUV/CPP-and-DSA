#include<iostream>
using namespace std;

int main()
{
    int marks[] = {23,45,67,89};

    cout<<marks[0]<<endl;
    cout<<marks[1]<<endl;
    cout<<marks[2]<<endl;
    cout<<marks[3]<<endl;

    marks[0] = 100;

    cout<<marks<<endl;
    cout<<*marks<<endl;

    // I/O by loop
    int arr[100];

    for(int i =0 ; i<100 ; i++ ){
        arr[i] = i+1;
    }

    for(int k=0 ; k<100 ; k++ ){
       cout<<arr[k]<<endl;
    }


    // pointer arithmatic
    int *ptr = &arr[0];

    for(int j=0 ; j<100 ; j++ ){
       cout<<"The address is "<<ptr<<endl;
       cout<<"The value at address is "<<*ptr<<endl;
       ptr++;
       cout<<endl<<endl;
    }


    return 0;
}