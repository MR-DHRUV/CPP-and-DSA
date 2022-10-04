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





// inserion can be occured at 3 places
// 0th index , that is before first node
// middle
// end

// insert at 7 means , insert after 7th node
// we can create list using insert function by insering elements one by one

// time : O(n)
void insert(struct Node *p, int index, int data)
{
    // new node in heap
    struct Node *newNode;
    newNode = new struct Node;
    newNode->data = data;

    // check for validity of index
    // if(index < 0 || index > count)
    // {
    //     return;
    // }

    if (index == 0)
    {
        // linking
        newNode->next = first;
        first = newNode;
    }

    else
    {
        // initially 1 par haii , n par le jane ke lie n-1 baar traverse karna padega
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        newNode->next = p->next;
        p->next = newNode;
    }

    // printList(p);
}






void sortedInsert(struct Node *p, int element)
{

    struct Node *n, *prev;
    n = new struct Node;
    n->data = element;

    // element to be inserted at 0 th position
    if (p->data > element)
    {
        n->next = first;
        first = n;
    }
    else
    {
        while (p != 0)
        {
            if (p->data > element)
            {
                n->next = prev->next;
                prev->next = n;
                return;
            }

            prev = p;
            p = p->next;
        }

        // element is greatest, and to be inserte
        n->next = prev->next;
        prev->next = n;
    }
}







int main()
{
    int arr[] = {1, 7, 9, 13, 18};
    int n = 5;
    createList(arr, n);

    sortedInsert(first, 8);
    printList(first);

    return 0;
}