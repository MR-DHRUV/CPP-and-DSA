#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

#define ni Node<int> *

// compare on the basis of data of nodes
class compare
{
public:
    bool operator()(ni a, ni b)
    {
        return a->data > b->data;
    }
};

ni mergeKLists(vector<ni> &listArray)
{
    // we will change all the links so that no extra space will be used
    // approach

    int n = listArray.size();
    priority_queue<ni, vector<ni>, compare> minHeap;

    ni head = NULL;
    ni p = head;

    // init
    for (int i = 0; i < n; i++)
    {
        if (listArray[i] != NULL)
        {
            minHeap.push(listArray[i]);
        }
    }

    // step 2
    while (minHeap.size() > 0)
    {
        ni temp = minHeap.top();
        ni nxt = temp->next;
        minHeap.pop();

        if (head == NULL)
        {
            head = temp;
            p = head;
        }
        else
        {
            p->next = temp;
            p = p->next;
        }

        if (nxt != NULL)
        {
            minHeap.push(nxt);
        }
    }

    return head;
}

int main()
{
    // disable default
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// set our properties
#ifndef IO_FROM_FILE
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
#endif

    return 0;
}