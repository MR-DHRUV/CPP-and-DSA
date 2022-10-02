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

Node *findMiddle(Node *head)
{
    int count = 0;
    Node *first = head;

    while (head != 0)
    {
        count++;
        head = head->next;
    }

    // in this case mid will not exist
    if (count % 2 == 0)
    {
        count = (count / 2) + 1;
    }

    // if even no of elements
    if (count % 2 == 0)
    {
        count = (count / 2) + 1;
    }
    else
    {
        count = (count + 1) / 2;
    }

    for (int i = 1; i < count; i++)
    {
        first = first->next;
    }

    return first;
}

int main()
{

    return 0;
}