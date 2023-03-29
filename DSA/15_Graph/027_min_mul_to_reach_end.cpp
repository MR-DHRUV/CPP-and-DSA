//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // we will impliment dijkstra's algo in the following way

        // say out source node is start and dest is end
        // as all the nodes will be bound to [0 to 10^5] we can say that we have to relax all 10^5 nodes
        // relax means the no of steps to make any no x from start are minimised

        // for any node its adj list is arr as we can multiply any no with any element of arr

        const int mod = 1e5;
        vector<int> dist(mod, INT_MAX);
        dist[start] = 0;

        // no need of priority queue as its a simple BFS for unweighted edges as every step will be counted as 1 , so first in queue means less steps...more like BFS
        queue<pair<int, int>> qt;
        qt.push({0, start});

        // complexity analysis
        // in the worst case we will generate 1e5 nodes so O(1e5)
        // unpredictable haii wese kabhi bhi 1 2 3 ... 9999 nahi bnega very hypothetical

        while (!qt.empty())
        {
            int steps = qt.front().first;
            int num = qt.front().second;

            qt.pop();

            // adj list
            for (int m : arr)
            {
                // calc new number
                int newNum = (num * m) % mod;

                // relax
                if (steps + 1 < dist[newNum])
                {
                    dist[newNum] = steps + 1;
                    qt.push({steps + 1, newNum});
                }

                // if we reach the num no more relaxation required as max relax ho chuka haii
                if (newNum == end)
                {
                    return steps + 1;
                }
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends