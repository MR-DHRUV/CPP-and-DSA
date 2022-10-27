#include <iostream>
using namespace std;

// in this type of priority queue we dont concider element as its priority,lower the element higher the priority

class Node
{
public:
    int priority;
    Node *next;
    int data;

    Node(int x , int p) : priority(p), next(NULL), data(x){};
};

class PriorityQueue
{
    Node *first;

public:
    PriorityQueue(int x , int p)
    {
        first = new Node(x , p);
    }

    void enqueue(int x , int p);
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

void PriorityQueue ::enqueue(int x , int p)
{
    Node *newNode = new Node(x , p);
    
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

    // if highest priority ka haii
    if (p < first->priority)
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
        if (temp->priority > p)
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
    PriorityQueue p(300 , 3);
    p.print();

    p.enqueue(500 , 3);
    p.print();

    p.enqueue(400 , 4);
    p.print();

    p.enqueue(100 , 1);
    p.print();

    p.enqueue(10000 , 1);
    p.print();

    p.enqueue(1856 , 0);
    p.print();

    p.enqueue(7 , 8);
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