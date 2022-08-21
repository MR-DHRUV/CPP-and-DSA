#include <iostream>
using namespace std;

int main()
{
    // while execution of a program it i sbrought to memory and memory is devided into 3 parts
    // code section => isme main code hota haii jisko execute krna haii

    // stack => The amount of memory required by a program deciced at compile time is called static memory  / stack frame / activation record of a function as anyting decided on or before compile time is called satic. The portion of memory where static momory is stored is called stack.

    // top most activation record belongs to the currently executing function

    // main is also treated as a function

    // once function is executed is activation recored or static memory is removed from the stack

    // This memory is auto allcoated and auto destroyed

    // Stack is LIFO => Last In First Out

    // stack is used for organised memory

    //////////////////////////////////////////////////////////////////////////////////

    // heap

    // heap is used for unorganised memory
    // heap is utilised as a resourse
    // jab chahiye ho tab leliya else free krdia

    // program cant access heap memory directly, it can be accessed using a pointer;

    // Heap declareation
    int *p;
    p = new int[5];

    // freeing it
    delete []p;

    return 0;
}