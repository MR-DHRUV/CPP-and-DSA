#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    int *h;
    int size;
    int len;

public:
    MaxHeap(){};
    MaxHeap(int x) : size(x), len(-1)
    {
        h = new int[size];
    };

    void create(vector<int> input);
    void insert(int x);

    void print();
};

void MaxHeap ::print()
{
    for (int i = 0; i <= len; i++)
    {
        cout << h[i] << " ";
    }

    cout << endl;
}

// complexity : O(logN)
void MaxHeap::insert(int x)
{
    if (len == size - 1)
    {
        cout << "Heap is full" << endl;
        return;
    }

    h[++len] = x;

    int i = len;

    while (i / 2 >= 0)
    {
        int parentIndex = i / 2;

        if (h[i] > h[parentIndex])
        {
            swap(h[i], h[parentIndex]);
            i = parentIndex;
        }
        else
        {
            break;
        }
    }
}

void MaxHeap ::create(vector<int> input)
{
    if (input.size() < 1)
    {
        return;
    }

    // if default constructor call hua haii
    if (size == 0)
    {
        len = -1;
        size = 2 * input.size();
        h = new int[size];
    }

    h[++len] = input[0];

    // O(NlogN)
    for (int i = 1; i < input.size(); i++)
    {
        insert(input[i]);
    }
}

int main()
{
    // MaxHeap mh(10);

    // mh.insert(3);
    // mh.insert(5);
    // mh.insert(7);
    // mh.insert(1);
    // mh.insert(2);

    // mh.print();


    MaxHeap mh;

    // order of elements in heap is independent of order of insertion if elements are same 
    vector<int> elements = {1,2,3,4,4,5,6,8};
    mh.create(elements);
    mh.print();

    return 0;
}