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

// removing duplicates from a sorted list
Node *uniqueSortedList(Node *head)
{
    // Write your code here.
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->next != NULL && curr->data == curr->next->data)
        {
            Node *next_to_next = curr->next->next;
            Node *toBeDeleted = curr->next;
            delete toBeDeleted;
            curr->next = next_to_next;
            // yaha pr curr aage ni badhaya as uska next bhi same ho skta haii toh ek skip ho jayga
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}

// removing from unsorted
Node *removeDuplicates(Node *head)
{
    // Write your code here

    if (head == NULL)
    {
        return head;
    }

    Node *curr = head->next;
    Node *prev = head;

    map<int,bool> visited;
    visited[head->data] = true;



    while(curr != NULL)
    {
        if(visited[curr->data] == true)
        {
            prev->next = curr->next;
            Node*temp = curr;

            curr = curr->next;
            delete temp;
        }
        else
        {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }

    }

    return head;

}

int main()
{

    return 0;
}