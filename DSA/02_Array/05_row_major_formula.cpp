#include <iostream>
using namespace std;

int main()
{
    // how 2-d array is managed by a compiler

    // 2d array on paper
    // 00 01 02
    // 10 11 12
    // 20 21 22


    // actually 
    // 00 01 02 10 11 12 20 21 22 or  00 10 20 01 11 21 02 12 22 

    // so we can say that this 2-d array is mapped into a 1d array
    // so how is this mapping done 

    // 1 Row major formula
    // 2 Column major formula


    // Row major mapping
    // 00 01 02 10 11 12 20 21 22

    // elements are copied row by row that is 1st row then 2nd and so on 

    // to access A[1][2] formula needed is 
    // Address(1,2) = base address + (no of colums in array * (sizeof(dataType))) * row needed to access +  2*sizeOf(dataType)

    // Address(r,c) = base address + (no of colums in array * (sizeof(dataType))) * r +  c*sizeOf(dataType)
    
    // Row Major Formula 👇 
    // Address(r,c) = base address + sizeOf(dataType) x {no of columns in array * r  + c}


    // C and Cpp follows row major formula






    return 0;
}