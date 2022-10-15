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

    Queue(int n) : size(n), front(0), back(0)
    {
        q = new int[size];
    }

    void enqueue(int x);
    int dequeue();
    bool isFull();
    bool isEmpty();
    int atFornt();
    void printArr(); 
};

// for testing
void Queue :: printArr()
{
    for (int i = 0; i < size; i++)
    {
        cout << q[i] << " ";
    }

    cout << endl;
}

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
    // in circular queue there can be 2 cases for full
    // case1 : _ 2 2 4 6 7
    // case1 : 2 2 _ 4 6 7

    // both are same , if we see circulary, the next position of back is 0 only, so this condiation handles all of the cases
    if ((back + 1) % size == front)
    {
        return true;
    }

    return false;
}

void Queue ::enqueue(int x)
{
    if (isFull() == false)
    {
        // aisa isilie kara taaki range se bahar na jaye
        // if array size is 7 and back is at last index that is 6 and we have space at front
        // new back will be (6+1)%7 = 0, which is what we want
        back = (back + 1) % size;
        q[back] = x;
    }
    else
    {
        cout << "Queue is full" << endl;
    }
}

int Queue::dequeue()
{
    int x = -1;

    if (isEmpty() == false)
    {
        front = (front + 1) % size;

        // we are returning the element obtained after dequeue operation
        x = q[front];

        // reseting Pointers
        // if(isEmpty())
        // {
        //     front = -1;
        //     back = -1;
        // }
    }
    else
    {
        cout << "Queue is empty" << endl;
    }

    return x;
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

// drawbacks with class Queue in 02
// space gets wasted whenever we dequeue as we will never be able to put an element at that location
// we are not able to reuse that space

// Solutions
// 1 Reseting pointers :
// jab elements daale aur then saare nikal lie then, humara front or back will be at index greater than equal to 0, so jab bhi front == back ho dono ko -1 par le aao
// not that effective solution

// 2 circular queue
// if queue gets filled till end and have space at front, we will add those elements in the front
// when we have deleted all the elements at the back then we will start our front and back from -1 again

// to impliment circular queue , we will start front and back from 0 , so that 0 is empty and hence we can add elements starting from index 0 when the back is at the end of queue

int main()
{
    Queue q(8);
    cout << q.atFornt() << endl;
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(1);

    q.printArr();
    
    q.dequeue();
    q.dequeue();
    cout << q.atFornt() << endl;
    q.dequeue();

    q.printArr();

    q.enqueue(100);
    q.enqueue(100);

    q.printArr();

    cout << q.atFornt() << endl;

    return 0;
}