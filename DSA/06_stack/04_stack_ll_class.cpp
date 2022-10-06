#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // default contructor
    Node() {}

    Node(int x) : data(x)
    {
        next = NULL;
    }
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    };

    void push(int x);
    void pop();
    bool isEmpty();
    int atTop();
    int peak(int pos);
};

bool Stack ::isEmpty()
{
    if (top == NULL)
    {
        return true;
    }

    return false;
}

int Stack ::atTop()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return -1;
    }

    return top->data;
}

void Stack ::push(int x)
{
    Node *newTop = new Node(x);

    if (newTop == NULL)
    {
        cout << "Heap is full" << endl;
        return;
    }

    newTop->next = top;
    top = newTop;
    return;
}

void Stack ::pop()
{
    if (isEmpty())
    {
        cout << "Already empty" << endl;
        return;
    }

    Node *temp = top;
    top = top->next;
    delete temp;
    return;
}

int Stack ::peak(int pos)
{
    if (isEmpty())
    {
        cout << "Already empty" << endl;
        return -1;
    }

    Node *temp = top;

    for (int i = 1; i < pos; i++)
    {
        if (temp->next == NULL)
        {
            cout << "Invalid Index" << endl;
            return -1;
        }

        temp = temp->next;
    }

    return temp->data;
}



int main()
{
    Stack *st = new Stack();

    cout << st->isEmpty() << endl;

    st->push(5);
    st->push(8);
    st->push(21);

    cout << st->atTop() << endl;
    st->pop();
    // cout<<st->atTop()<<endl;
    // st->pop();
    // cout<<st->atTop()<<endl;
    // st->pop();
    // st->pop();
    // st->pop();

    cout<<st->peak(3)<<endl;
    cout<<st->peak(1)<<endl;
    cout<<st->peak(2)<<endl;

    return 0;
}