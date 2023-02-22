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

// true to index
struct Node *deleteCircular(struct Node *a, int index)
{
    struct Node *prev;
    struct Node *head = a;
    struct Node *start = a;

    if (index <= 1)
    {

        // updating last node to point on 2nd node
        while (a->next != head)
        {
            a = a->next;
        }

        // prev is to be deleted in this case

        a->next = head->next;
        start = head->next;
        delete head;
    }

    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            prev = a;
            a = a->next;
        }

        prev->next = a->next;
        delete a;
    }

    return start;
};

Node *reverseCLL(Node *head)
{
    if(head == NULL)
    {
        return head;
    }

    Node *prev = NULL, *curr = head, *next = NULL;

    while (curr->next != head)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // for last node
    curr->next = prev;

    // first node will point towards last node
    head->next = curr;

    return curr;
}

int main()
{
    int arr1[] = {6, 7, 9, 13, 18, 89, 100};
    int arr2[] = {16, 27, 19, 103, 108, 589, 700};
    int n = 7;
    struct Node *A = createCircularList(arr1, n);
    printCircularList(A);
    A = reverseCLL(A);
    printCircularList(A);

    // struct Node *C = deleteCircular(A, 1);

    // printCircularList(C);

    return 0;
}