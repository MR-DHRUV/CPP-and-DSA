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




// reversing can be done using 2 methods 
// 1 reversing elements
// 2 reversing data

// time  : O(n)
// space : O(n)
void reverse_by_elements(struct Node *p)
{
    // to traverse 2nd time
    struct Node *start = p;

    int n = countNodes(p);
    int arr[n];

    int i = 0;
    while(p != 0 )
    {
        arr[i] = p->data;
        p = p->next;
        i++;
    }

    while(start != 0 )
    {
        // i-- is done first as in last iteration of above loop i is incrimented and has gone out of index
        i--;
        start->data = arr[i];
        start = start->next;
    }
}

// best method
// time  : O(N)
// space : O(1)
void reverse_by_links(struct Node *p)
{
    // sliding pointers

    // so to swap list by reversing the links we need 3 pointers

    // 1 to store the address of next node before we swap the link
    // 1 to point to the node whoose link to be swapped
    // 1 to hold the address of previos node where it has to be swapped

    // yeh ek ke peeche ek chalte hain , isile sliding pointers kehte hain
    struct Node *q , *r;

    q = NULL;
    r = NULL;

    while(p != 0)
    {
        // r will point to q
        r = q;

        // q will point to p
        q = p;

        p = p->next;

        // q->next was initially poining to p , but now it will point to r , the node prev to it
        q->next = r;
    }

    // we have to make first equal to last node as it will be the new first after it
    // as p has incremented and is zero ,  thus we have used q
    first = q;

}


int main()
{
    int arr[] = {6, 7, 9, 13, 18, 89, 100};
    int n = 7;
    createList(arr, n);

    printList(first);

    reverse_by_links(first);
    printList(first);
 

    return 0;
}