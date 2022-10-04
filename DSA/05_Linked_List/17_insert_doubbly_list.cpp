#include <iostream>
using namespace std;

// doubbly linked list
// every node stores the address of its ahead and previous node
// thus we can access elements ahead of it and before it
// it solves the problem on linked list , that we cannot traverse them backwards

struct Node
{
    // stores the address of previous node
    struct Node *prev;

    int data;

    // stores the address of next node
    struct Node *next;
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
}


struct Node *createDoubleList(int arr[], int n)
{
    struct Node *first;
    struct Node *last;
    first = new struct Node;
    first->data = arr[0];
    first->next = NULL;
    first->prev = NULL;

    last = first;

    for (int i = 1; i < n; i++)
    {
        struct Node *t;
        t = new struct Node;
        t->data = arr[i];
        t->next = NULL;
        t->prev = last;

        last->next = t;
        last = t;
    }

    return first;
};


int countNodes(struct Node *p)
{   
    // while address of next block is not null 
    int count = 0;

    while(p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}


void insert(struct Node *A , int data , int index)
{
    if(index == 0)
    {
        
    }
}


int main()
{
    int arr1[] = {6, 7, 9, 13, 18, 89, 100};
    int arr2[] = {16, 27, 19, 103, 108, 589, 700};
    int n = 7;

    struct Node *A = createDoubleList(arr1, n);
    printList(A);
    cout<<countNodes(A)<<endl;

    return 0;
}