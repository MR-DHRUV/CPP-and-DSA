#include <bits/stdc++.h>
using namespace std;

// we need this data structure as we will requre next element of every array and since its a 2-d array we need 2 indices
class cont
{
public:
    int data;
    int i;
    int j;

    cont(){};
    cont(int a, int b, int c) : data(a), i(b), j(c){};
};

class compare
{
public:
    bool operator()(cont *a, cont *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Approach 1 : brute force
    // 1 create an ans array and insert all the elements into it
    // 2 sort ans array
    // complexity : O(nklognk) where total elements are n*k = nk

    // Approach 2 :
    // make a min heap and initialize it with first element of all the arrays
    // and put the top element of min heap into ans
    // then we have to put next element of array from which we have pushed, that is uss array ka next element daaldo jiska sabse chota element tha
    // we have to do this till heap size is greater than 1

    // complexity : O(n*k logk)


    // ans vector
    vector<int> ans;

    // heap of node which will compare on the basis of node.data
    priority_queue<cont *, vector<cont *>, compare> minHeap;

    // Init : O(klogK)
    for (int i = 0; i < k; i++)
    {
        cont *temp = new cont(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    // step 2 
    // we will process n*k - k elements i.e n*k only 
    // each time we push time taken is logK since the size of heap is k
    // O(n*k logk)
    while (minHeap.size() > 0)
    {
        // push top element into ans array
        cont *temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        if ((temp->j) + 1 < kArrays[temp->i].size())
        {
            temp->j += 1;
            temp->data = kArrays[temp->i][temp->j];
            minHeap.push(temp);
        }
    }

    return ans;
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