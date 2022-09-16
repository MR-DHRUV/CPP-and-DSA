#include<iostream>
using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5};
    char str[] = "abcde";

    char *strPtr = &str[0];
    char *strPtr1 = str;

    // returns the address of 1st block as array is not a default data type  
    cout<<arr<<endl;
    
    // string is a data type so we will se string as output not the address of first block 
    // cout have diffrentrent implimentation in case of char and char arrays
    cout<<str<<endl;
    cout<<strPtr<<endl;
    cout<<strPtr1<<endl;

    // returns the address of 1st block
    cout<<&str<<endl;


    //what will happen if \0 will not be present
    // cout will continue to print blocks until it finds a null character
    char temp = 'p';
    char *ptr = &temp;
    cout<<ptr<<endl;



    


    return 0;
}