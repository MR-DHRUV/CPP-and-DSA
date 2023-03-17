//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void printMat(vector<vector<int>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printArr(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout<<arr[i]<<" "; 
        }
    
        cout<<endl;
        
    }
    

    vector<int> checkCycleKahn(int V, vector<vector<int>> &adj, vector<int> &inDeg)
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

        if(topo.size() == V)
        {
            reverse(topo.begin(),topo.end());
        }
        else
        {
            topo.clear();
        }

        return topo;
    }

public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
    {
        // Code here

        // problem reduced to detecting cycle in a directed graph as if there are three tasks
        // 1->2->3 and 3->1
        // such tasks can never be finished

        // finding topo sort using kahn's algo to determine presence of a cycle in a directed graph

        vector<vector<int>> adj(n);
        vector<int> inDeg(N, 0);

        for (auto edge : prerequisites)
        {
            adj[edge[0]].push_back(edge[1]);
            inDeg[edge[1]]++;
        }

        printMat(adj);
        printArr(inDeg);
        

        return checkCycleKahn(N, adj, inDeg);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends