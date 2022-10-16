#include <iostream>
#include <deque>
using namespace std;

class Deque
{
    int *q;
    int front;
    int back;
    int size;

public:
    // Initialize your data structure.
    Deque(int n) : size(n), front(-1), back(-1)
    {
        q = new int[size];
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if (isFull())
        {
            return false;
        }

        if (isEmpty())
        {
            front = back = 0;
        }
        else if (front == 0 && back != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }

        q[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if (isFull())
        {
            return false;
        }

        if (isEmpty())
        {
            front = back = 0;
        }
        else if (back == size - 1 && front != 0)
        {
            back = 0;
        }
        else
        {
            back++;
        }

        q[back] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if (isEmpty())
        {
            return -1;
        }

        int x = getFront();

        if (front == back)
        {
            front = back = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        return x;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if (isEmpty())
        {
            return -1;
        }

        int x = getRear();

        if (back == front)
        {
            front = back = -1;
        }
        else if (back == 0)
        {
            back = size - 1;
        }
        else
        {
            back--;
        }

        return x;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return q[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return q[back];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if (front == -1)
        {
            return true;
        }

        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if ((front == 0 && back == size - 1) || (back == (front - 1) % size))
        {
            return true;
        }

        return false;
    }
};

int main()
{
    // also called dequeue
    // we can do insertion and deletion from both the ends that are front and back

    return 0;
}