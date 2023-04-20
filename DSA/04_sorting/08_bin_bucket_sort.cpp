#include <bits/stdc++.h>
using namespace std;

#define ul unsigned long

int Max(ul A[], long n)
{
    ul max = A[0];

    for (long i = 1; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    return max;
}

// Linked List node
class Node
{
public:
    ul data;
    Node *next;
};

void Insert(Node **ptrBins, ul idx)
{
    Node *temp = new Node;
    temp->data = idx;
    temp->next = nullptr;

    if (ptrBins[idx] == nullptr)
    { // ptrBins[idx] is head ptr
        ptrBins[idx] = temp;
    }
    else
    {
        Node *p = ptrBins[idx];
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

ul Delete(Node **ptrBins, long idx)
{
    Node *p = ptrBins[idx];
    ptrBins[idx] = ptrBins[idx]->next;
    ul x = p->data;
    delete p;
    return x;
}

void BucketSort(ul A[], long n)
{
    ul max = Max(A, n);

    // Create bins array
    Node **bins = new Node *[max + 1];

    // Initialize bins array with nullptr
    for (long i = 0; i < max + 1; i++)
    {
        bins[i] = nullptr;
    }

    // Update count array values based on A values
    for (long i = 0; i < n; i++)
    {
        Insert(bins, A[i]);
    }

    // Update A with sorted elements
    long i = 0;
    long j = 0;
    while (i < max + 1)
    {
        while (bins[i] != nullptr)
        {
            A[j++] = Delete(bins, i);
        }
        i++;
    }

    // Delete heap memory
    delete[] bins;
}

int main()
{
    // bucket/bin sort
    // similar to count sort
    // here we have bins/ linked list in count array and whenever we enconter any element we add it to the bin by inserting that element in the linkedlist of that index

    // useless as high space complexity
    // bin baat linked list kyu banani haii

    ul arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    long n = sizeof(arr) / sizeof(arr[0]);

    BucketSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}