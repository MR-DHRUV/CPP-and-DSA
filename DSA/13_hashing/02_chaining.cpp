#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(){};
    Node(int x) : data(x), next(NULL){};
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

Node *sortedInsert(Node *head, int element)
{
    Node *p = head;
    Node *n, *prev;
    n = new Node(element);

    if (p == NULL)
    {
        n->next = NULL;
        head = n;
        return head;
    }

    // element to be inserted at 0 th position
    if (p->data > element)
    {
        n->next = p;
        p = n;
    }
    else
    {
        while (p != 0)
        {
            if (p->data > element)
            {
                n->next = prev->next;
                prev->next = n;
                return head;
            }

            prev = p;
            p = p->next;
        }

        // element is greatest, and to be inserted at the end
        n->next = prev->next;
        prev->next = n;
    }

    return head;
}

Node *searchList(Node *p, int target)
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

// simple modulas hash function
class HashTable
{
    Node **H;

public:
    int modVal;

    HashTable(){};
    HashTable(int x) : modVal(x)
    {
        *H = new Node[modVal];
        for (int i = 0; i < modVal; i++)
        {
            H[i] = NULL;
        }
    };

    int Hash(int key)
    {
        return key % modVal;
    }

    void insert(int key)
    {
        int index = Hash(key);
        H[index] = sortedInsert(H[index], key);
        printList(H[index]);
    }

    bool search(int key)
    {
        int index = Hash(key);
        Node *isPresent = searchList(H[index], key);

        if (isPresent == NULL)
        {
            return false;
        }

        return true;
    }
};

int main()
{
    // Open HashTable is achieved with the help of chaining

    // h(x)= x%mod_value
    // it is implimented using array of pointers, i.e its a array in which each index points to a linked list
    // each list is maintained in sorted order to make searching faster

    // Loading factor(lamda) = no of keys (n)/ mod_value
    // mod_value is size of hash table
    // analysis of hash function is done on the basis of loading factor
    // we always ensure loading factor to be less than or equal to 0.7

    // time taken for successfull search
    // t = 1 for obtaining address of pointer where we can possibly found that element using hash functiom
    // t = lamda/2 for average successfull search time for searching in the linked list
    // t = 1 + lamda/2

    // Avg Unsuccessfull search
    // t = 1 for obtaining address of pointer where we can possibly found that element using hash functiom
    // t = lamda for average unsuccessfull search time for searching in the linked list
    // for unsuccessfull search whole list has to be traversed
    // t = 1 + lamda

    // Operations like insertion, deletion and searching are same as that of linked list

    HashTable HT(10);

    HT.insert(5);
    HT.insert(25);
    HT.insert(15);
    HT.insert(6);

    cout<<HT.search(5)<<endl;
    cout<<HT.search(25)<<endl;
    cout<<HT.search(15)<<endl;
    cout<<HT.search(254)<<endl;

    return 0;
}