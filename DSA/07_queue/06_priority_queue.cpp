#include <iostream>
#include <queue>

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

    friend class PriorityQueue;

public:
    // contructor
    Queue()
    {
        front = NULL;
        back = NULL;
    };
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
        cout << "Queue is empty" << endl;
        return;
    }

    Node *temp = front;
    front = front->next;
    delete (temp);
}

int Queue ::atFornt()
{
    if (isEmpty())
    {
        return -1;
    }

    return front->data;
}

class PriorityQueue
{
    Queue *p;
    Node *first;
    int priority;
    int maxPriority;

public:
    PriorityQueue(int totalPriorities)
    {
        p = new Queue[totalPriorities]();
        first = NULL;
        priority = -1;
        maxPriority = totalPriorities;
    }

    void insert(int x, int pr);
    void remove();
    bool empty();
    void firstPrinter();
};

bool PriorityQueue ::empty()
{
    if (first == NULL)
    {
        return true;
    }

    return false;
}

void PriorityQueue ::firstPrinter()
{
    if (!empty())
    {
        cout << first->data << endl;
        return;
    }

    cout << "Empty" << endl;
}

void PriorityQueue ::insert(int x, int pr)
{
    if (pr > maxPriority)
    {
        cout << "Invalid Priority" << endl;
        return;
    }

    if (p[pr - 1].isEmpty())
    {
        Node *nextNode = new Node(x);
        p[pr - 1].front = nextNode;
        p[pr - 1].back = nextNode;
    }
    else
    {
        p[pr - 1].enqueue(x);
    }

    // updating the first , if an element of higher priority enters
    if (pr > priority)
    {
        priority = pr;
        first = p[priority - 1].front;
    }
}

void PriorityQueue ::remove()
{
    // sabse pahle highest priority wala hatega
    if (empty())
    {
        return;
    }

    p[priority - 1].dequeue();

    // if no element of priority equal to that, then we must shift our first
    first = p[priority - 1].front;

    if (first == NULL)
    {
        // current ke
        for (int i = priority - 1; i >= 0; i--)
        {
            if (p[i].front != NULL)
            {
                first = p[i].front;
                priority = i;
                break;
            }
        }
        
        if (first == NULL)
        {
            priority = -1;
        }
    }
}

int main()
{

    PriorityQueue p(5);

    p.insert(30, 3);
    p.insert(100, 3);
    p.insert(150, 5);
    p.insert(200, 4);
    p.insert(201, 4);

    p.firstPrinter();

    p.remove();
    p.firstPrinter();

    p.remove();
    p.firstPrinter();

    p.remove();
    p.firstPrinter();

    return 0;
}