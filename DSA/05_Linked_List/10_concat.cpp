#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createList(int arr[], int n)
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

    return first;
};

void printList(struct Node *p)
{
    // while address of next block is not null
    while (p != NULL)
    {
        cout << (p->data) << " ";
        p = p->next;
    }

    cout << endl;
};

// links a to b
void concatList(struct Node *A, struct Node *B)
{
    // jab tak kisi node me next block ka address 0 ya null nahi haii
    while (A->next != 0)
    {
        A = A->next;
    }
    struct Node *nextn = new struct Node;
    nextn->data = B->data;
    nextn->next = B->next;

    A->next = nextn;
    delete B;
};


int main()
{
    int arr1[] = {6, 7, 9, 13, 18, 89, 100};
    int arr2[] = {16, 27, 19, 103, 108, 589, 700};
    int n = 7;
    struct Node *A = createList(arr1, n);
    struct Node *B = createList(arr2, n);
    printList(A);
    printList(B);

    concatList(A, B);
    printList(A);

    return 0;
}