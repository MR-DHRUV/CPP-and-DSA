//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    // global vars
    vector<int> assigned;
    vector<bool> vis;

    bool canBeAssigned(int app, vector<vector<int>> &adj)
    {
        // iter on jobs
        auto &jobs = adj[app];

        for (int i = 0; i < jobs.size(); i++)
        {
            // intrested
            if (jobs[i] == 1 && !vis[i])
            {
                vis[i] = true;

                // this job is not assigned to anyone or seat can be made empty
                if (assigned[i] == -1 || canBeAssigned(assigned[i], adj))
                {
                    assigned[i] = app; // assigned to applicant
                    return true;
                }
            }
        }

        return false;
    }

public:
    int maximumMatch(vector<vector<int>> &g)
    {
        // maximum bi partite matching means we need maximum possible pairs from 2 graphs that satisfies the given condition
        // we are trying to assign a job to a person in such a way that we are assigning empty jobs at first

        // when we are at a stage when a job cant be assign to a person then we are try to make a person holding that job leave his seat and find another job for himself so that this job can be assigned to current person

        // this algo is called kuhn's algo

        int m = g.size();
        int n = g[0].size();
        int ans = 0;

        assigned = vector<int>(n, -1);

        for (int i = 0; i < m; i++)
        {
            // to inhibit infinite toggling
            vis = vector<bool>(n, false);

            if (canBeAssigned(i, g))
                ans++;
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> G(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> G[i][j];
        }
        Solution obj;
        int ans = obj.maximumMatch(G);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends