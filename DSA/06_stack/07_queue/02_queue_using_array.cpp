#include <iostream>
using namespace std;

// if we only use 1 pointer that is back pointer then deletion of first element takes O(N) time as we have to shift all the elements at the back in the array

class Queue
{
    int *q;
    int front;
    int back;

public:
    int size;

    Queue(int n) : size(n), front(-1), back(-1)
    {
        q = new int[size];
    }

    void enqueue(int x);
    void dequeue();
    bool isFull();
    bool isEmpty();
    int atFornt();
};

bool Queue ::isEmpty()
{
    if (front == back)
    {
        return true;
    }

    return false;
}

bool Queue ::isFull()
{
    if (back == size - 1)
    {
        return true;
    }

    return false;
}

void Queue ::enqueue(int x)
{
    if (isFull() == false)
    {
        back++;
        q[back] = x;
    }
    else
    {
        cout << "Queue is full" << endl;
    }
}

void Queue::dequeue()
{
    if (isEmpty() == false)
    {
        front++;
        q[front] = -1;
    }
    else
    {
        cout << "Queue is empty" << endl;
    }
}

int Queue ::atFornt()
{
    if (isEmpty() == false)
    {
        return q[front + 1];
    }
    else
    {
        cout << "Queue is empty" << endl;
    }

    return -1;
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


    return 0;
}