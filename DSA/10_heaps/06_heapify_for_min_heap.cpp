#include <bits/stdc++.h>
using namespace std;

    void heapify(vector<int> &arr, int n, int i)
    {
        // i is the element to be placed at ts correct position
        int left = (2 * i) + 1;

        while (left < n)
        {
            int right = left + 1;

            // checking for right
            if (right < n && arr[right] < arr[left])
            {
                if (arr[i] > arr[right])
                {
                    swap(arr[i], arr[right]);
                    i = right;
                    left = (2 * i) + 1;
                }
                else
                {
                    break;
                }
            }
            else if (arr[i] > arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
                left = (2 * i) + 1;
            }
            else
            {
                break;
            }
        }
    }

// reccursive
void heapifyRec(vector<int> &arr, int n, int i)
{
    // i is the element to pe placed at the correct position

    int smallest = i;

    int left = (2*i)+ 1;
    int right = left + 1;

    // finding min child if it exisits
    if(right < n & arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if(left < n & arr[left] < arr[smallest])
    {
        smallest = left;
    }


    // swapping
    if(smallest != i)
    {
        swap(arr[i],arr[smallest]);
        // placing largest at its correct index
        heapifyRec(arr,n,smallest);
    }
}


void heapifyArr(vector<int> &arr)
{
    int n = arr.size();
    // we will not start from 0 as we dont have to process the leaf elements
    // no of leaf elements = (n+1)/2
    // index of last leaf = (n/2)

    // so we'll start from n/2 -1 and we have to compare i with its children and swap, in short we have to use delete from heap algo

    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, arr.size(), i);
        // heapifyRec(arr, arr.size(), i);
    }
}

void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    // heapify
    // faster method to convert array into heap

    // complexity : O(N)

    // works on the fact that whenver a element is inserted it is moved from bottom to top that is from leaf to root
    // and whenever element is deleted, last element takes it place and it is brought towards bottom from top

    // insert : bottom->top
    // delete : top->bottom

    // we start from last element of array and compare it with its child, if child is larger we swap it
    // as we are starting from end we dont have to process the leaf elements, thus less time complexity
    // just using this staragy we have to do very few swappings than traditional method.

    // vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> a = {5,6,8,4,2,7,10,6,9,1,5,4,7,2,1};
    heapifyArr(a);
    printArr(a);

    return 0;
}