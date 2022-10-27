#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x) : data(x), next(NULL){};
};

class Queue
{
    Node *front;
    Node *back;

public:
    // contructor
    Queue(int x)
    {
        Node *nextNode = new Node(x);
        front = nextNode;
        back = nextNode;
    };

    void enqueue(int x);
    void dequeue();
    // bool isFull(); as linked list
    bool isEmpty();
    int atFornt();
};

bool Queue ::isEmpty()
{
    if (front == NULL)
    {
        return true;
    }

    return false;
}

void Queue::enqueue(int x)
{
    Node *nextNode = new Node(x);

    // checking if heap is full or not
    if (nextNode == NULL)
    {
        cout << "Heap is full" << endl;
        return;
    }

    back->next = nextNode;
    back = back->next;
}

void Queue::dequeue()
{
    if (isEmpty())
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    Node *temp = front;
    front = front->next;
    delete (temp);
}

int Queue ::atFornt()
{
    if(isEmpty())
    {
        return -1;
    }

    return front->data;
}

int main()
{
    Queue q(8);
    cout << q.atFornt() << endl;
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(1);
    cout << q.atFornt() << endl;
    q.dequeue();
    cout << q.atFornt() << endl;
    q.dequeue();
    cout << q.atFornt() << endl;
    q.dequeue();
    cout << q.atFornt() << endl;
    q.dequeue();
    q.dequeue();
    cout << q.atFornt() << endl;

    return 0;
}