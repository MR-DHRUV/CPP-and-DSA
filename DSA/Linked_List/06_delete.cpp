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

// deletion can be done at two positions
// 1 first
// 2 any other ahead of 1st
void deleteList(struct Node *p , int index)
{
    struct Node *prev;

    if(index == 0){

        // pointing to 1st node
        prev = first;
        
        // pointing to 2nd node
        first = first->next;

        delete prev;
    }

    else{

        for (int i = 0; i < index-1; i++)
        {
            prev = p;
            p = p->next;
        }

        prev->next = p->next;
        delete p;
        
    }
}







int main()
{
    int arr[] = {1, 7, 9, 13, 18, 89, 90};
    int n = 7;
    createList(arr, n);

    printList(first);

    deleteList(first , 7);
    printList(first);

    deleteList(first , 0);
    printList(first);

    deleteList(first , 3);
    printList(first);

    deleteList(first , 3);
    printList(first);

    return 0;
}