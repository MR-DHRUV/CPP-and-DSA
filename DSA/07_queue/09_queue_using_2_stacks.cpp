#include <bits/stdc++.h>
using namespace std;

class twoStackQueue
{
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
};

bool twoStackQueue::isEmpty()
{
    if (s1.size() == 0 && s2.size() == 0)
    {
        return true;
    }

    return false;
}

void twoStackQueue::enqueue(int x)
{
    // whenever we enqueue we push a element in stack s1
    s1.push(x);
}

int twoStackQueue::dequeue()
{
    // whenever we dequeue we pop a element from stack s2

    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return -1;
    }

    if (s2.size() == 0)
    {
        while (s1.empty() == false)
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int x = s2.top();
    s2.pop();

    return x;
}

int main()
{

    twoStackQueue q;

    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(1);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    q.enqueue(95);
    q.enqueue(89);
    q.enqueue(87);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    q.enqueue(495);
    q.enqueue(489);
    q.enqueue(487);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}