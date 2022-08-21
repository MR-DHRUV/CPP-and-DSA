#include<iostream>
using namespace std;

int main()
{

    // A[d1][d2][d3][d4]

    // row major
    /// WE GO LEFT TO RIGHT 
    // address(i1,i2,i3,i4) = base address  + [i1*d2*d3*d4 + i2*d3*d4 + i3*d4 + i4]* w
    

    // here w is size of data type

    // column major
    // WE GO RIGHT TO LEFT
    // address(i1,i2,i3,i4) = base address  + [i4 * d3*d3*d1 + i3*d2*d1 + i2*d1 + i1]* w




    return 0;
}