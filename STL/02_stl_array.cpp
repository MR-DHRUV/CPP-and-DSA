#include<bits/stdc++.h>
using namespace std;





int main()
{
    int basicArray[] = {1,2,3};

    array<int , 4> arr = {1,2,3,4};

    cout<<arr.size()<<endl;

    // access elements
    cout<<arr[0]<<endl;
    cout<<arr.at(0)<<endl;


    // to check if empty or not , returns 0 or 1
    cout<<arr.empty()<<endl;


    // to get element at first and last index;
    cout<<arr.front()<<endl;
    cout<<arr.back()<<endl;

    

    return 0;
}