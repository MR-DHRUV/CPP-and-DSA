#include <bits/stdc++.h>
using namespace std;

// we can either include or exclude any item
// dp will be used to reduce time complexity

void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int solve(int item, int capacity, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
{
    // base condition
    if (item == 0)
    {
        if (weight[item] <= capacity)
            return value[item];

        return 0;
    }

    if (dp[item][capacity] != -1)
        return dp[item][capacity];

    // exclude
    int ans = solve(item - 1, capacity, weight, value, dp);

    // check if its possible to include
    if (capacity >= weight[item])
    {
        ans = max(ans, value[item] + solve(item - 1, capacity - weight[item], weight, value, dp));
    }

    return dp[item][capacity] = ans;
}

// here i am trying to fill the dp array starting from 0
int solveTab(vector<int> &weight, vector<int> &value, int &n, int &maxWeight)
{
    vector<int> dp(maxWeight + 1, -1); // space optimization
    // either i will take current item or not

    // base case
    for (int w = 0; w <= maxWeight; w++)
    {
        if (weight[0] <= w)
        {
            dp[w] = value[0];
        }
        else
        {
            dp[w] = 0; // exclude 0th item
        }
    }

    for (int item = 1; item < n; item++)
    {
        for (int w = maxWeight; w >= 0; w--)
        {
            // exclude
            int ans = dp[w];

            // check if its possible to include
            if (w >= weight[item])
            {
                ans = max(ans, value[item] + dp[w - weight[item]]);
            }

            dp[w] = ans;
        }
    }

    return dp[maxWeight];
}

class Solution
{
    // here i am trying to fill the dp array starting from 0 
    int solveTab(int n, int weight[], int value[], int &maxWeight)
    {
        vector<int> dp(maxWeight + 1, -1); // space optimization
        // either i will take current item or not

        // base case
        for (int w = 0; w <= maxWeight; w++)
        {
            if (weight[0] <= w)
            {
                dp[w] = value[0];
            }
            else
            {
                dp[w] = 0; // exclude 0th item
            }
        }

        for (int item = 1; item < n; item++)
        {
            for (int w = maxWeight; w >= 0; w--)
            {
                // exclude
                int ans = dp[w];

                // check if its possible to include
                if (w >= weight[item])
                {
                    ans = max(ans, value[item] + dp[w - weight[item]]);
                }

                dp[w] = ans;
            }
        }

        return dp[maxWeight];
    }

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        return solveTab(n,wt,val,W);
    }
};

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, -1));

    // return solve(n - 1, maxWeight, weight, value, dp);

    return solveTab(weight, value, n, maxWeight);
}

int main()
{

    return 0;
}