#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    int *h;
    int size;
    int len;
    int maxLen;

public:
    MaxHeap()
    {
        size = 0;
        len = -1;
    };

    MaxHeap(int x) : size(x), len(-1)
    {
        maxLen = len;
        h = new int[size];
    };

    void create(vector<int> input);
    void insert(int x);
    void del();

    void print();
    void printArr();

    // O(NlogN)
    void heapSort();

    // heapify
    // faster method to create heap from array

    // works on the fact that whenver a element is inserted it is moved from bottom to top that is from leaf to root
    // and whenever element is deleted, last element takes it place and it is brought towards bottom from top

    // insert : bottom->top
    // delete : top->bottom

    // create heap in O(N), faster than traditional method
    void heapify(vector<int> arr);
};

void MaxHeap ::print()
{
    if (len == -1)
    {
        cout << "Heap is empty" << endl;
        return;
    }

    for (int i = 0; i <= len; i++)
    {
        cout << h[i] << " ";
    }

    cout << endl;
}

void MaxHeap ::printArr()
{
    for (int i = 0; i <= maxLen; i++)
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
    maxLen = len;

    int i = len;

    // as index 0 will have no parent
    while (i > 0)
    {
        int parentIndex = i / 2;

        // comparing it with its parent
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
        maxLen = len;
        size = input.size();
        h = new int[size];
    }

    h[++len] = input[0];

    // O(NlogN)
    for (int i = 1; i < input.size(); i++)
    {
        insert(input[i]);
    }
}

void MaxHeap ::del()
{

    if (len < 1)
    {
        len = -1;
        return;
    }

    // We can only delete root element from a heap
    // that means we can only delete highest priority element

    /*
            30
          /   \
        20     15
       / \    /  \
      5  10  12   6

    */

    // When we delete root our heap will look like this

    /*
             20
           /   \
         5     15
          \    /  \
          10  12   6

   */

    // problem
    // 1 Inpomplete tree, thus empty space , so invalid heap
    // 2 not every element follows the property of max heap

    // solution
    // put last element in place of root
    // then compare children of new root with new root and swap new root with max value and keep on doing it

    // 1
    /*
            6
          /   \
        20     15
       / \    /
      5  10  12

    */

    // 2
    /*
           20
          /   \
        6     15
       / \    /
      5  10  12

    */

    /*
           20
          /   \
        10     15
       / \    /
      5   6  12

    */

    // step 1
    int removedElement = h[0];
    h[0] = h[len--];

    // step 2
    int i = 0;           // on new root
    int j = (2 * i) + 1; // on root's left child, +1 as our index starts from 0

    // we have to repeat this swapping until a node has no child that is j is out of bound
    while (j <= len)
    {
        // checking right child
        // jo bada hoga left ya right me usse swap krenge
        if (h[j + 1] > h[j])
        {
            j++;
        }

        // child is greater
        if (h[i] < h[j])
        {
            swap(h[i], h[j]);

            // now we have corrected the above tree and now we have to correct the lower tree so bringing i to swapped  element and j again to its left child
            i = j;
            j = (2 * i) + 1;
        }
        else
        {
            break;
        }
    }

    // concides the fact
    // it we start storing deleted elements at last indices , then we will have sorted array and this is called heap sort
    // they will be in decending order

    // storing that element at last index
    h[len + 1] = removedElement;
}

void MaxHeap ::heapSort()
{
    for (int i = 0; i < size; i++)
    {
        del();
    }
}

void MaxHeap ::heapify(vector<int> arr)
{
    if (arr.size() < 1)
    {
        return;
    }

    if (size == 0)
    {
        size = arr.size();
        len = -1;
        maxLen = size-1;
        h = new int[size];
    }

    // index of least leaf node : n/2
    // so we have to start processing from n/2-1 till 0

    for (int i = (arr.size() / 2) - 1; i >= 0; i--)
    {
        int curr = i;
        int left = (2 * curr) + 1;

        while (left < arr.size())
        {
            int right = left + 1;

            if (right < arr.size() && arr[right] > arr[left])
            {
                if (arr[curr] < arr[right])
                {
                    swap(arr[curr], arr[right]);
                    curr = right;
                    left = (2 * curr) + 1;
                }
                else
                {
                    break;
                }
            }
            else if (arr[curr] < arr[left])
            {
                swap(arr[curr], arr[left]);
                curr = left;
                left = (2 * curr) + 1;
            }
            else
            {
                break;
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        h[++len] = arr[i];
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

    vector<int> elements = {1, 2, 3, 4, 4, 5, 6, 8};
    // mh.create(elements);
    mh.heapify(elements);
    mh.print();

    mh.heapSort();
    mh.printArr();

    // mh.del();
    // mh.printArr();
    // mh.print();

    // mh.del();
    // mh.printArr();
    // mh.print();

    return 0;
}