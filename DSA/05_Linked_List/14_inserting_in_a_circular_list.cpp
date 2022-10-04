#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createCircularList(int arr[], int n)
{
    // initializing first node
    struct Node *first = NULL;

    struct Node *t;
    struct Node *last;

    // setup a new node
    first = new struct Node;
    first->data = arr[0];
    first->next = NULL;

    // last is first as 1 element only
    last = first;

    for (int i = 1; i < n; i++)
    {
        // setup a new node
        t = new struct Node;
        t->data = arr[i];
        t->next = NULL;

        // make current last point to new node
        last->next = t;

        // update last
        last = t;
    }

    // making last point to first
    last->next = first;

    return first;
};

void printCircularList(struct Node *p)
{
    struct Node *head = p;

    // while address of next block is not null
    while (p != NULL)
    {
        cout << (p->data) << " ";
        p = p->next;

        // jab p wapas aajaye head pr tab break krdo
        if (p == head)
        {
            break;
        }
    }

    cout << endl;
};

// inserting after nth node
struct Node * insertCircular(struct Node *a, int element, int index)
{
    struct Node *head = a;

    struct Node *t = new struct Node;
    t->data = element;

    if (index == 0)
    {
        t->next = head;


        // updating last node to make it point on t (new head)
        while(a->next != head)
        {
            a = a->next;
        }

        a->next = t;
        head = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            a = a->next;
        }

        t->next = a->next;
        a->next  = t;
    }

    return head;
}

int main()
{
    int arr1[] = {6, 7, 9, 13, 18, 89, 100};
    int arr2[] = {16, 27, 19, 103, 108, 589, 700};
    int n = 7;
    struct Node *A = createCircularList(arr1, n);
    printCircularList(A);

    struct Node *C = insertCircular(A, 7000, 6);

    printCircularList(C);

    return 0;
}