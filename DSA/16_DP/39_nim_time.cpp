//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    long long solve(long long t, long long l, int &n, unordered_map<int, vector<long long>> &location, unordered_map<int, long long> dp[])
    {
        if (t == n)
            return abs(l); // return to 0

        if (dp[t].count(l))
            return dp[t][l];

        // only 1 friut
        if (location[t].size() == 1)
        {
            return dp[t][l] = abs(l - location[t][0]) + solve(t + 1, location[t][0], n, location, dp);
        }

        // both choices are in different direction
        if ((l - location[t][0]) * (l - location[t][1]) <= 0)
        {
            // choice 1 : l to front and front to last
            long long ans = abs(l - location[t][0]) + abs(location[t][0] - location[t][1]) + solve(t + 1, location[t][1], n, location, dp);

            // choice 2 : l to last the last to front
            ans = min(ans, abs(l - location[t][1]) + abs(location[t][0] - location[t][1]) + solve(t + 1, location[t][0], n, location, dp));

            return dp[t][l] = ans;
        }

        // both choices are in same direction
        // left
        if (l - location[t][0] > 0)
            return dp[t][l] = abs(l - location[t][0]) + solve(t + 1, location[t][0], n, location, dp);

        // right
        return dp[t][l] = abs(l - location[t][1]) + solve(t + 1, location[t][1], n, location, dp);
    }

public:
    long long minTime(int n, vector<int> &locations, vector<int> &types)
    {
        // type compression

        // loading into set to have all unique numbers in types in a sorted form
        set<int> st(types.begin(), types.end());

        int num = 0;
        unordered_map<int, int> mp; // to store which is compressed to what

        // map
        for (auto &it : st)
        {
            mp[it] = num++;
        }

        // convert
        for (int &it : types)
        {
            it = mp[it];
        }

        // store min and max for any range
        unordered_map<int, vector<long long>> location;

        for (int i = 0; i < n; i++)
        {
            int &type = types[i];
            location[type].push_back(locations[i]);

            if (location[type].size() == 2)
            {
                int x = min(location[type][0], location[type][1]);
                int y = max(location[type][0], location[type][1]);
                location[type][0] = x, location[type][1] = y;
            }
            else if (location[type].size() > 2)
            {
                int x = min({location[type][0], location[type][1], location[type][2]});
                int y = max({location[type][0], location[type][1], location[type][2]});
                location[type][0] = x, location[type][1] = y;
                location[type].pop_back();
            }
        }

        // dp[i][j] => ith picked at j'th location
        unordered_map<int, long long> dp[num];

        return solve(0ll, 0ll, num, location, dp);
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

        vector<int> locations(n);
        for (int i = 0; i < n; i++)
        {
            cin >> locations[i];
        }

        vector<int> types(n);
        for (int i = 0; i < n; i++)
        {
            cin >> types[i];
        }

        Solution obj;
        long long res = obj.minTime(n, locations, types);

        cout << res << endl;
    }
}

// } Driver Code Ends