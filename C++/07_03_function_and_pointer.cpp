#include<iostream>
using namespace std;

void print(int *p)
{
    cout<<"The value is "<<(*p)<<endl;
    cout<<"The address is "<<(p)<<endl;
}

void update(int *p)
{
    *p = *p + 1; 
}

// int arr[] is equivalent to int *arr;
// thus sizeof(arr) prints the size of 1block
void sumArr(int arr[] , int n)
{
    int sum = 0;
    cout<<"The size of arr is "<<sizeof(arr)<<endl;

   for (int i = 0; i < n; i++)
   {
    sum+= arr[i];
   }

   cout<<sum<<endl;
   
    
}


int main()
{
    int val = 9 ; 
    int *ptr = &val;

    print(ptr);


    // refer c codes / misc for detailed pointers

    update(ptr);
    print(ptr);

    int arr[] = {1 ,2 ,3 ,4, 5};
    sumArr(arr , 5);

    // 5*sizeof(int) = 5*4 = 20
    cout<<"The size of arr is "<<sizeof(arr)<<endl;

    
    return 0;
}