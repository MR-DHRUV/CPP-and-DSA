#include<iostream>
using namespace std;

int main()
{
    // during execution compiler converts name into address so that it can be used 
    // so in dynamic arrays memory is allocated at runtime, so how will compiler give an address to this at compile time

    // compiler uses a formula to obtain the address

    // name of array is called the base address of the array and its the address of 1st block

    // address = base address + index * sizeof(dataType);

    // so compiler uses base address formula and it is updated on runtime and the process is called data binding


    // in cpp we cannot have indexes starting from 1 
    // as one operation done will be extra due to change in formula 
    // address' = base address + (index -1) * sizeof(dataType);


    return 0;
}