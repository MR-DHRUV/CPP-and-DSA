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

    bool isEmpty();
    bool isFull();
    void push(int x);
    void pop(void);
    int peak(int index);
    int atTop();
};

bool Stack ::isEmpty()
{
    if (top == -1)
    {
        return true;
    }

    return false;
}

bool Stack ::isFull()
{
    if (top == size - 1)
    {
        return true;
    }

    return false;
}

// O(1)
void Stack ::push(int x)
{

    // if stack is full
    if (isFull())
    {
        cout << "Stack is full" << endl;
        return;
    }

    top++;

    s[top] = x;
}

// O(1)
void Stack ::pop()
{
    // if empty ho pahle se hi
    if (isEmpty())
    {
        cout << "Stack is already empty" << endl;
        return;
    }

    s[top] = -2;
    top--;
}

int Stack ::peak(int pos)
{
    if (pos > top)
    {
        cout << "Invalid index" << endl;
        return -1;
    }

    // we need to return pos'th element from top
    // +1 as index are from 0  while position are from 1
    // pos == 1 means that we need the top element
    return s[top - pos + 1];
}

int Stack ::atTop()
{
    return peak(1);
}

int main()
{
    Stack st(7);
    cout << st.isEmpty() << endl;
    cout << st.isFull() << endl;

    st.push(9);
    st.push(10);
    st.push(18);
    st.push(11);
    st.push(5);
    st.push(27);
    st.push(40);

    // cout << st.isEmpty() << endl;
    // cout << st.isFull() << endl;
    // cout << st.top << endl;

    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();

    // cout << st.isEmpty() << endl;
    // cout << st.isFull() << endl;
    // cout << st.top << endl;

    cout << st.peak(1) << endl;
    cout << st.peak(2) << endl;
    cout << st.peak(4) << endl;
    cout << st.atTop() << endl;

    return 0;
}