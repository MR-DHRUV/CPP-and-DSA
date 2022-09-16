#include <bits/stdc++.h>
using namespace std;

// bubble sort

// 10 1 7 6 14 9

// neibghour se compare karao aur swap kara do

// round 1 starts ⚡

// 1 10 7 6 14 9
// 1 7 10 6 14 9
// 1 7 6 10 14 9

// when a is leass tha b , continue

// 1 7 6 10 14 9
// 1 7 6 10 9 14

// round 1 completed
// and so on till n-1 rounds .............

// har round me largest elemenr place ho jayge so algo n-i ke lie chalani haii
// total rounds : n-1;
// ith round me n-i time chalega

void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        bool isSwaped = false;

        for (int j = 0; j < arr.size() - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwaped = true;
            }

            // optimazation
        }

        if (isSwaped)
        {
            break;
        }
    }
}

// time complexity : O(n^2) always ;
// space complexity : O(1);

// best case time complexity = O(1)

int main()
{

    return 0;
}


// it is called bubble sort as heaviest element gets sorted at first, like heavy bubble goes down earliest
// adaptive, jaise hi sort ho jayga ruk jayga bekar ke comparisions nahi krega
// stable


