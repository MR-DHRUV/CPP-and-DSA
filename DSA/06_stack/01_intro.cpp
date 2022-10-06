#include <iostream>
using namespace std;

class Stack
{
    int *s;

public:
    int size;
    int top;

    Stack(int x) : size(x)
    {
        s = new int[size];

        // initially koi element nahi haii toh top is outside the stack
        top = -1;
    }
};

int main()
{
    // stack , ek ke upar ek
    // LIFO : last in first out
    // we can only access last element in stack
    // all operations like access , detete , insert can only be done at last index

    // stack ADT
    // space for storing the elements
    // top pointer

    // we can make stack using both array and linked list

    Stack st(5);
    cout << st.top << endl;
    cout << st.size << endl;

    return 0;
}