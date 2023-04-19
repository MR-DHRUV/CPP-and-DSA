#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int s, int e, vector<int> &arr, map<int, map<int, int>> &maxVal, vector<vector<int>> &dp)
    {
        // atleast we need 2 nodes as we have to make a strict bst
        // 1 node can't be partioned further, thus its value will this only
        if (s >= e)
            return 0;

        if (dp[s][e] != -1)
            return dp[s][e];

        // we are partioning the array to make left and right sub trees
        // we will multiply the product of max leaf elements of right and left sub trees and add it to ans
        // we have to retun min ans of all possible partitionings

        int ans = INT_MAX;

        for (int i = s; i < e; i++)
        {
            ans = min(ans, maxVal[s][i] * maxVal[i + 1][e] + solve(s, i, arr, maxVal, dp) + solve(i + 1, e, arr, maxVal, dp));
        }

        return dp[s][e] = ans;
    }

    int solveTab(int n, vector<int> &arr)
    {
        map<int, map<int, int>> maxVal;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < arr.size(); i++)
        {
            maxVal[i][i] = arr[i];
            int maxi = arr[i];

            for (int j = i + 1; j < arr.size(); j++)
            {
                maxi = max(maxi, arr[j]);
                maxVal[i][j] = maxi;
            }
        }

        for (int s = n - 2; s >= 0; s--)
        {
            for (int e = s + 1; e < n; e++)
            {
                int ans = INT_MAX;

                for (int i = s; i < e; i++)
                {
                    ans = min(ans, (maxVal[s][i] * maxVal[i + 1][e]) + dp[s][i] + dp[i + 1][e]);
                }

                dp[s][e] = ans;
            }
        }

        return dp[0][n - 1];
    }

    // O(N) solution
    int intutive(vector<int> &arr)
    {
        // we are trying to make minimum pairs of condicutive elements 
        // eg : 3 6 4 2 5 7
        //  [3 6] 4 [2 5] 7
        // no 4 will se ki uske sath kiso anna chahiye 
        // [3 6] [4 [2 5]] 7
        // [3 6] [[4 [2 5]] 7]
        // [[3 6] [[4 [2 5]] 7]]

        // we are finding next greater element from right for every element and stack is used to preserve the order of keys as we are given inorder traversal

        vector<int> st = {1000000000};
        int ans = 0;

        for (int a : arr)
        {
            while (st.back() <= a)
            {
                int midNode = st.back();
                st.pop_back();

                ans += (midNode * min(a, st.back()));
            }

            st.push_back(a);
        }

        for (int i = 2; i < st.size(); i++)
        {
            ans += (st[i] * st[i - 1]);
        }

        return ans;
    }

public:
    int mctFromLeafValues(vector<int> &arr)
    {
        // mapping maximum values for any inerval i,j
        map<int, map<int, int>> maxVal;

        for (int i = 0; i < arr.size(); i++)
        {
            maxVal[i][i] = arr[i];
            int maxi = arr[i];

            for (int j = i + 1; j < arr.size(); j++)
            {
                maxi = max(maxi, arr[j]);
                maxVal[i][j] = maxi;
            }
        }

        vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, -1));

        // strict bst hai so 0 ya end index pr partition hua toh left ya right baised bst bn jayga
        return solve(0, arr.size() - 1, arr, maxVal, dp);
    }
};

int main()
{

    return 0;
}