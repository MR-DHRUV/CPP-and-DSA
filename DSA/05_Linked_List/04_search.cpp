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

struct Node *searchList(struct Node *p, int target)
{
    while (p != 0)
    {
        if (p->data == target)
        {
            // returns address of that node which have data == target
            return p;
        }
        p = p->next;
    }

    return NULL;
}

// improving linear search
// same as array : transposition , move to head

// transposiotion : jo element search kia gaya haii aur woh present haii , us node ko aage move karo
// move to head : jo element search kia gaya haii aur woh present haii , usse first me le aao

// move to head
// to move to head , we have to do 2 operations
// 1 us wale ko nikalo aur starting me lagao then usse jo initial first se link karo
// 2 jaha se nikala haii uske aage aur pichle node ko link kardo
struct Node *searchListMTH(struct Node *p, int target)
{
    // points to node previous to p
    struct Node *prev;

    while (p != 0)
    {
        if (p->data == target)
        {

            // jaha se nikala haii uske aage aur pichle node ko link krdo
            prev->next = p->next;

            // insering in front
            p->next = first;
            first = p;

            // returns address of that node which have data == target
            return p;
        }

        prev = p;

        // neccesary condition to traverse the list
        p = p->next;
    }

    return NULL;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    createList(arr, n);

    // binary search cant be used as we cannot use indexes , thus we cant calculate end and mid;

    // address
    //  cout<<(searchList(first,5))<<endl;
    //  cout<<(searchList(first,0))<<endl;
    //  cout<<(searchList(first,2))<<endl;

    // cout<<(searchList(first,5))->data<<endl;
    // cout<<(searchList(first,2))->data<<endl;

    cout << (searchListMTH(first, 5))->data << endl;
    cout << (searchListMTH(first, 2))->data << endl;

    return 0;
}