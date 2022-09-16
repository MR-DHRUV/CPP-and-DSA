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

    // name of array points to the first block
    int *addressOfFirstBlock = arr;
    cout<<arr<<" "<<&arr<<endl;

    // pointer arithmatic
    int *ptr = &arr[0];
    
    for(int j=0 ; j<100 ; j++ ){
       cout<<"The address is "<<ptr<<endl;
       cout<<"The value at address is "<<*ptr<<endl;
       ptr++;
       cout<<endl<<endl;
    }

    // chalaki

    int a[] = {23 , 122 , 41 , 67};

    int i = 3;

    // these both gives the same result as 
    // arr[i] = *(arr+i);
    // i[arr] = *(i+arr);

    cout<<*(a+i)<<endl;
    cout<<*(i+a)<<endl;

    cout<<a[i]<<endl;
    cout<<i[a]<<endl;

    // int pointers are of 8bytes in 64bit architecture 


    // contents of symbol table cant be changed
    // jab mne ek array bnaya arr toh usse ek address ke sath map krdia jata haii in memory
    // aur woh address aur name symbol table me store hota haii

    // so arr = arr+1 or arr++  are invalid operations as their address cant be changed
    // so  to access further locations we use pointer

    return 0;
}