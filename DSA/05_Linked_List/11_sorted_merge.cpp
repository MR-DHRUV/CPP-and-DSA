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

struct Node *mergeList(struct Node *A, struct Node *B)
{
    // base case
    if (A == NULL && B == NULL)
    {
        return A;
    }
    else if (A == NULL)
    {
        return B;
    }
    else if (B == NULL)
    {
        return A;
    }

    // points to first element of new mergerd list
    struct Node *third;

    // it will point at last of merged list at every iteration , and will be used for linking further nodes in the list
    struct Node *last;

    // A

    if (A->data > B->data)
    {
        // list starts from 1st element of B in this case
        third = B;
        last = B;
        B = B->next;
        last->next = NULL;
    }
    else
    {
        third = A;
        last = A;
        A = A->next;
        last->next = NULL;
    }

    while (A != NULL && B != NULL)
    {
        if (A->data > B->data)
        {
            // pervious block ka next ko new block par le aao , then last ko uss block pr le aao
            last->next = B;
            // last ab b par aajana chahiye na , tabhi list aage badhegi
            last = B;
            B = B->next;
            last->next = NULL;
        }
        else
        {
            last->next = A;
            last = A;
            A = A->next;
            last->next = NULL;
        }
    }

    if (A != NULL)
    {
        last->next = A;
    }
    if (B != NULL)
    {
        last->next = B;
    }

    return third;
}

int main()
{
    int arr1[] = {6, 7, 9, 13, 18, 89, 100};
    int arr2[] = {16, 27, 79, 103, 108, 589, 700};
    int n = 7;
    struct Node *A = createList(arr1, n);
    struct Node *B = createList(arr2, n);
    printList(A);
    printList(B);

    // concatList(A, B);
    // printList(A);

    struct Node *C = mergeList(A, B);
    printList(C);

    return 0;
}