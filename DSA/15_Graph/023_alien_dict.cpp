//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    vector<int> getTopoKahn(int V, vector<vector<int>> &adj, vector<int> &inDeg)
    {
        queue<int> qt;
        vector<int> topo;

        for (int i = 0; i < V; i++)
        {
            if (inDeg[i] == 0)
            {
                qt.push(i);
            }
        }

        if (qt.size() == 0)
        {
            return topo;
        }

        while (!qt.empty())
        {
            int f = qt.front();
            qt.pop();

            topo.push_back(f);

            for (auto nbr : adj[f])
            {
                inDeg[nbr]--;

                if (inDeg[nbr] == 0)
                {
                    qt.push(nbr);
                }
            }
        }

        return topo;
    }

public:
    string findOrder(string dict[], int N, int K)
    {
        // intution to use topoSort
        // we want alien alphabetical order
        // thus we have to compare strings in the alien dict and find out by which character they are distinguished
        // abd abc
        // ab == ab
        // d comes before c
        // thus we will have pairs that what comes before what => topoSort

        // How to apply topo sort
        // we have first K alphabets and lets index them from 0 to K-1 where 0 corresponds to a , 1 to b and so on
        // we'll figure out what comes before what and make a graph

        /*
            baa abcd abca cab cad

            from 0 and 1
            b a => 1 0
            d a => 3 0
            a c => 0 2
            b d => 1 3

            now we have edges and topo sort will be our ans
        */

        // say k = 5 for current test case
        // so we dont have any data for last alphabet or e thus we can have them anywhere in the order

        // Now our problem has been reduced to finding topoSort of charaters that create ordering


        // extention of problem: when we will not have a valid ordering
        /*
            case 1
            abcd abc 
            in above case large string is before small string so invalid dict return -1

            case 2
            dict that creates cycle in the graph like
            a b 
            b a 
            so we cant find topo sort for such case, will be detected in kahn 

        */


        vector<vector<int>> adj(K);
        vector<int> inDeg(K, 0);

        for (int i = 0; i < N - 1; i++)
        {
            int j = 0;

            while (dict[i][j] == dict[i + 1][j])
            {
                j++;
            }

            if (j == dict[i].length())
            {
                continue;
            }

            // create edge in adj list
            adj[dict[i][j] - 'a'].push_back(dict[i + 1][j] - 'a');

            // update indegree
            inDeg[dict[i + 1][j] - 'a']++;
        }

        vector<int> topo = getTopoKahn(K, adj, inDeg);
        string ans;

        for (auto a : topo)
        {
            ans.push_back(char(a + 'a'));
        }

        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b)
{
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++)
    {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends