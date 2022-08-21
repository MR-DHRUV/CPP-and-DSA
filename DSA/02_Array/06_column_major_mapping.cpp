#include <iostream>
using namespace std;

int main()
{
    // how 2-d array is managed by a compiler

    // 2d array on paper
    // 00 01 02
    // 10 11 12
    // 20 21 22


    // column major mapping 
    // elemts are mapped column by column
    // 00 10 20 01 11 21 02 12 22


    // address(1,2) : base address + (sizeOf(dataType) * no of rows * 2 ) + sizeOf(dataType) * 1
    // address(r,c) : base address + (sizeOf(dataType) * no of rows * c ) + sizeOf(dataType) * r
    // address(r,c) : base address + (sizeOf(dataType) * (no of rows * c + r)
    // formula : base address  

    






    return 0;
}