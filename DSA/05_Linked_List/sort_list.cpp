#include <bits/stdc++.h>
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

struct Node *getMid(struct Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

struct Node *mergeList(struct Node *left, struct Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }

    // Node *ans = new Node(-1);
    Node *ans = new Node;
    Node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    return ans->next;
}

struct Node *merge_sort(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // obtaining mid
    struct Node *mid = getMid(head);

    struct Node *left = head;
    struct Node *right = mid->next;

    // break list into 2 equal heads
    mid->next = NULL;

    // sorting both halves
    left = merge_sort(left);
    right = merge_sort(right);

    // merging right and left kist
    Node *result = mergeList(left, right);

    return result;
}

int main()
{

    return 0;
}