#include <iostream>
using namespace std;

// in this type of priority queue we concider element as its priority,lower the element higher the priority

class Node
{
public:
    int data;
    Node *next;

    Node(int x) : data(x), next(NULL){};
};

class PriorityQueue
{
    Node *first;

public:
    PriorityQueue(int x)
    {
        first = new Node(x);
    }

    void enqueue(int x);
    void dequeue();
    bool isEmpty();
    void print();
};

void PriorityQueue :: print()
{
    Node *p = first;

    // while address of next block is not null
    while (p != NULL)
    {
        cout << (p->data) << " ";
        p = p->next;
    }

    cout << endl;
}

bool PriorityQueue ::isEmpty()
{
    if (first == NULL)
    {
        return true;
    }

    return false;
}

void PriorityQueue ::enqueue(int x)
{
    Node *newNode = new Node(x);
    
    if(newNode == NULL)
    {
        cout<<"Heap is full"<<endl;
        return;
    }

    if (isEmpty())
    {
        first = newNode;
        return;
    }

    // if hight priority ka haii
    if (x < first->data)
    {
        newNode->next = first;
        first = newNode;
        return;
    }

    Node *prev;
    Node *temp = first;

    // we want smaller element to be at first everytime
    while (temp != NULL)
    {
        if (temp->data > x)
        {
            newNode->next = prev->next;
            prev->next = newNode;
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    // element is greatest
    newNode->next = prev->next;
    prev->next = newNode;
    return;
}


void PriorityQueue ::dequeue()
{
    if(!isEmpty())
    {
        Node *temp = first;
        first = first->next;
        delete (temp);
        return;
    }

    cout<<"Empty"<<endl;
    return;
} 

int main()
{
    PriorityQueue p(3);
    p.print();

    p.enqueue(5);
    p.print();

    p.enqueue(4);
    p.print();

    p.enqueue(1);
    p.print();

    p.enqueue(1);
    p.print();

    p.enqueue(0);
    p.print();

    p.enqueue(7);
    p.print();

    p.dequeue();
    p.print();

    p.dequeue();
    p.print();

    p.dequeue();
    p.print();

    p.dequeue();
    p.dequeue();
    p.dequeue();
    p.dequeue();
    p.dequeue();
    p.dequeue();
    p.dequeue();
    p.dequeue();
    p.dequeue();


    return 0;
}