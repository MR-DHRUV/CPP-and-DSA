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

    //making last point to first
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
        if(p == head)
        {
            break;
        }
    }

    cout << endl;
};



// circular linked list
// its a linked list in which last node points to first node
// we use term head to represent first node as there is no existanve of first
 
// benifit : 
// we can traverse the list circularly


// we can make first node with null data and make it pointing to 2nd node from where the circular linked list will start
// this method id benificial as it can be used to access the head node of the list






int main()
{
    int arr1[] = {6, 7, 9, 13, 18, 89, 100};
    int arr2[] = {16, 27, 19, 103, 108, 589, 700};
    int n = 7;
    struct Node *A = createCircularList(arr1, n);
    printCircularList(A);


    return 0;
}