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


long long sumList(struct Node *p)
{
    long long sum = 0;

    while (p != 0)
    {
        sum+=p->data;
        p = p->next;
    }

    return sum;
    
}

int maxList(struct Node *p)
{
    int max = p->data;
    p = p->next;

    while (p != 0)
    {
        if(p->data > max)
        {
            max = p->data;
        }

        p = p->next;
    }

    return max;
    
}

int minList(struct Node *p)
{
    int min = p->data;
    p = p->next;

    while (p != 0)
    {
        if(p->data < min)
        {
            min = p->data;
        }

        p = p->next;
    }

    return min;
    
}

int main()
{
    int arr[] = {1,2,9,4,0};
    int n = 5;
    createList(arr,n);

    cout<<sumList(first)<<endl;
    cout<<maxList(first)<<endl;
    cout<<minList(first)<<endl;

    return 0;
}