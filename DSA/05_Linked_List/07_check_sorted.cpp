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



int chkSorted(struct Node *p)
{
    int prev = p->data;
    p = p->next;

    while (p != 0)
    {   
        // cout<<prev<<" "<<p->data<<endl;

        if(prev > p->data)
        {
            return false;
        }

        prev = p->data;
        p = p->next;
    }

    return true;
}



int main()
{
    int arr[] = {6, 7, 9, 13, 18, 89, 100};
    int n = 7;
    createList(arr, n);

    printList(first);
    cout<<chkSorted(first)<<endl;

    return 0;
}