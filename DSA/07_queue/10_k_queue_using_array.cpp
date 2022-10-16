#include <iostream>
using namespace std;

class Kqueue
{
    int *front;
    int *rear;

    // we are using this to indicate next free slot and once we use a slot we will store the index to next element to that queue in that slot to make a link
    int *next;
    int free;
    int k;

public:
    int *q;

    Kqueue(int n, int K)
    {
        k = K;
        q = new int[n];
        front = new int[k];
        rear = new int[k];

        // initializing front and rear
        for (int i = 0; i < K; i++)
        {
            front[i] = -1;
        }

        next = new int[n];

        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }

        // as index n-1 ke baad koi khaali jagah nahi haii
        next[n - 1] = -1;

        free = 0;
    }

    bool enqueue(int x, int qn);
    int dequeue(int qn);
};

bool Kqueue ::enqueue(int x, int qn)
{
    if (qn >= k)
    {
        cout << "Invalid Queue No" << endl;
        return -1;
    }

    // checking if array is full or not
    if (free == -1)
    {
        cout << "Array is Full" << endl;
        return false;
    }

    // storing the current free spot
    int index = free;

    // pointing free to the next free spot
    free = next[index];

    // if we are pushing the first element
    if (front[qn] == -1)
    {
        front[qn] = index;
    }
    else
    {
        // making a link between last element of this queue to its new last using next array
        next[rear[qn]] = index; // iska matlab yeh haii ki qn ka next element khoojne yaha jana haii
    }

    // standard steps

    // marking next[index] as used
    next[index] = -1;

    // pushing the element
    q[index] = x;

    // updateing the rear of qn
    rear[qn] = index;

    return true;
};

int Kqueue::dequeue(int qn)
{
    if (qn >= k)
    {
        cout << "Invalid Queue No" << endl;
        return -1;
    }

    // checking if qn is empty or not
    if (front[qn] == -1)
    {
        cout << "Queue " << qn << " is already empty" << endl;
        return -1;
    }

    int index = front[qn];

    // calculating the new front of this queue, nahi hoga agar next to -1 aajayga as used toh mark kara hi haii is space ko
    front[qn] = next[qn];

    // since index free haii ab, so we cannot determine ki kon index ko point karega but we can make next[index] point to a free location, so humne index ke next par current free laga dia aur free ko index ke equal kr dia
    next[index] = free;
    free = index;

    int x = q[index];
    q[index] = -1;

    return x;
}

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{

    int k = 3, n = 10;
    Kqueue ks(n, k);

    // Let us put some items in queue number 2
    ks.enqueue(15, 2);
    ks.enqueue(45, 2);

    // Let us put some items in queue number 1
    ks.enqueue(17, 1);
    ks.enqueue(49, 1);
    ks.enqueue(39, 1);

    // Let us put some items in queue number 0
    ks.enqueue(11, 0);
    ks.enqueue(9, 0);
    ks.enqueue(7, 0);

    printArr(ks.q, n);

    cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
    printArr(ks.q, n);

    cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
    printArr(ks.q, n);

    cout << "Dequeued element from queue 3 is " << ks.dequeue(0) << endl;
    printArr(ks.q, n);

    return 0;
}