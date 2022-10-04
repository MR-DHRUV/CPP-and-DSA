#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

} *first = NULL;
// initialised first as null

void createList(int arr[], int n)
{
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

int removeDuplicates(struct Node *p)
{
    struct Node *prev;
    prev = p;
    p = p->next;

    while (p != 0)
    {
        if (prev->data == p->data)
        {
            // here order of steps is very very important

            // 1 previous will point to next of next block, and the node with duplicate entry will be removed from the list 
            prev->next = p->next;
            
            // a new node is required to point to p so that it can be deleted from heap
            struct Node *del;

            // del will point to p    
            del = p;

            // p will point to its nect block , so that iterations can go on
            p = p->next;

            // now del can be deleted
            delete del;
        }
        else
        {
            prev = p;
            p = p->next;
        }
    }
}

int main()
{
    int arr[] = {6, 6, 9, 9, 18, 89, 100, 100, 100};
    int n = 9;
    createList(arr, n);

    printList(first);
    removeDuplicates(first);
    printList(first);

    return 0;
}