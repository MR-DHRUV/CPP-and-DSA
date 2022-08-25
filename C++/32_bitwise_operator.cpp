#include <iostream>
using namespace std;

// bitwise operations

// how a no is stored in bits
// eg: 1

// 8-bytes ka hota haii int standard

//  0   0   0   0   0  0  0  1
// 128  64  32  16  8  4  2  1

// H = H<<2;
// saare bits 2 baar left shift ho gaye

//  0   0   0   0   0  1  0  0
// 128  64  32  16  8  4  2  1

// 1 and 0  = 0

// and / or operation

//          binary
// a = 10   1010
// b = 6    0110

// a and b  0010
// a or b   1110

// masking and merging

int main()
{

    int H = 1;
    cout << H << endl;

    H = H << 2;
    cout << H << endl;

    H = H << 2;
    cout << H << endl;

    H = H << 2;
    cout << H << endl;

    int a = 10;
    int b = 6;
    cout << (a & b) << endl;
    cout << (a | b) << endl;

    // masking : pata lagana ki koi bit 0 haii ya 1
    // jaike pata lagana haii ko 2nd poision wala bit on haii ya nahi

    //                  76543210
    // toh a=1 liya i.e 00000001

    // we need to check 2 so a = a<<2;

    // Now
    //                  76543210
    // toh a=1 liya i.e 00000100

    // id and gives non-zero value then bit is 1 else its 0

    int c = 16;
    //               76543210
    // c=16 liya i.e 00010000

    int d = 1;
    // checking at 2
    d = d << 2;

    cout << (c & d) << endl; // result is 0 , that is not present

    // merging : kisi bit ko 1 set krna
    // like 2 pr det krna haii 1


    //                  76543210
    // toh a=1 liya i.e 00000001

    //a<<2; 
    
    // Now
    //                  76543210
    // toh a=1 liya i.e 00000100

    int e = 16;
    //               76543210
    // e=16 liya i.e 00010000

    // a=1  00000100
    // e=16 00010000
    //  Or  00010100 // merged

    cout<<(a|e)<<endl;     




    return 0;
}