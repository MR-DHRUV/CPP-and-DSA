#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


// time : O(N)
// space O(1)
Node* sortListI(Node *head)
{
    // Write your code here.
    if(head == NULL)
    {
        return head;
    }

    int H[] = {0,0,0};
    Node *temp = head;

    while(temp != NULL)
    {
        H[temp->data]++;
        temp = temp->next;
    }

    temp = head;

    for(int i = 0 ; i <= 2; i++)
    {
        while(H[i] != 0)
        {
            temp->data = i;
            H[i]--;
            temp = temp->next;
        }
    }

    return head;

}




// better approach
void insertAt(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = tail->next;
}

Node *sortListII(Node *head)
{

    // 3 nodes bnayenge
    // 1 me 0 wale saare node laga lenge , ek me 1 wale aur 1 me 2 waale
    // last me merge krdenge

    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    Node *zeroTail = zeroHead;
    Node *oneTail = oneHead;
    Node *twoTail = twoHead;

    Node *curr = head;

    while (curr != NULL)
    {
        int value = curr->data;

        if (value == 0)
        {
            // zeroTail ka next curr krdega as curr ka data 0 haii
            insertAt(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAt(oneTail, curr);
        }

        else if (value == 2)
        {
            insertAt(twoTail, curr);
        }

        curr = curr->next;
    }
    // now we have a separate list for 0 , 1 , 2

    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main()
{

    return 0;
}