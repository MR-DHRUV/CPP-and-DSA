#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

bool isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return true;
    }

    return false;
}

// there's nothing like isFull in linked list as it is dynamic , no fixed size

void push(struct Node *&top, int x)
{
    struct Node *newTop = new struct Node;

    // checking that heap is full o not
    if (newTop == NULL)
    {
        cout << "Heap is full" << endl;
        return;
    }

    newTop->data = x;
    newTop->next = top;
    top = newTop;

    return;
}

void pop(struct Node *&top)
{
    if (isEmpty(top))
    {
        cout << "Empty" << endl;
        return;
    }

    struct Node *temp = top;
    top = top->next;
    delete temp;
    return;
}

int atTop(struct Node *top)
{
    return top->data;
}

int peak(struct Node *top, int pos)
{
    if (isEmpty(top))
    {
        cout << "Empty" << endl;
        return -1;
    }

    for (int i = 1; i < pos; i++)
    {
        if (top->next == NULL)
        {
            cout << "Inavid position" << endl;
            return -1;
        }
        top = top->next;
    }

    return top->data;
}

int main()
{
    struct Node *stack = new struct Node;
    stack->data = 100;
    stack->next = NULL;

    cout << isEmpty(stack) << endl;

    push(stack, 5);
    push(stack, 7);
    push(stack, 71);
    cout << atTop(stack) << endl;
    pop(stack);
    cout << atTop(stack) << endl;

    cout<<"peak : "<<peak(stack , 2)<<endl;

    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);

    cout << isEmpty(stack) << endl;

    return 0;
}

