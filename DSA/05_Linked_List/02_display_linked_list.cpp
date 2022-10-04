#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

}*first = NULL;
// initialised first as null 

void createList(int arr[] , int n)
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
    while(p != NULL)
    {
        cout<<(p->data)<<" ";
        p = p->next;
    }

    cout<<endl;
}

// time : O(n)
// space : O(1)
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

int main()
{
   
    // traversing 
    // p = p->next;
    // p is the address of next node, so while address is not zero or not null
    // while(p != 0) or while(p != null)

    int arr[] = {1,2,3,4,5};
    int n = 5;
    createList(arr,n);

    printList(first);
    
    cout<<countNodes(first)<<endl;


    return 0;
}