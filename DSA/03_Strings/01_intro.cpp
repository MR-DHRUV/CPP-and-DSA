#include<iostream>
using namespace std;

int main()
{

    // ASCII Codes and Unicodes
    // ASCII are for english language while Unicodes are for native/ national language

    // ASCII Codes

    // A-65
    // Z-90

    // a-97
    // z-122

    // 0-48
    // 9-67

    // starts from 0 and ends at 127
    // so 7 bits are enough to store them
    // so in comuter momory minimum allocation os of 1 byte so 1 byte is allocated


    //Unicode
    // 2 bytes / 16 bits
    // represented in hexa decimal 

    //String
    // char can be declared inside '' only , "" is wrong while opposite for string
    // string is a character array 


    // string when made by this format is ended with \0
    char mystr0[10] = {'D','H','R','U','V'};
    char mystr1[] = {'D','H','R','U','V'};


    string myStr2 = "Dhruv";


    // creating string in heap;
    char *name = "Dhruv";
    //here name to points to a string in a heap

    
    cout<<mystr0<<endl;
    cout<<myStr2<<endl;
    cout<<name<<endl;







    return 0;
}