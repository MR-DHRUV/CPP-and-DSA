#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int> &days, vector<int> &cost, vector<int> &dp)
{
    if (i >= days.size())
        return 0;

    if (dp[i] != -1)
        return dp[i];

    // 1 day pass
    int ans = cost[0] + solve(i + 1, days, cost, dp);

    // 7 day pass
    int maxTravel = i;

    for (; maxTravel < days.size() && days[maxTravel] < days[i] + 7; maxTravel++)
        ;
    ans = min(ans, cost[1] + solve(maxTravel, days, cost, dp));

    // 30 day pass
    maxTravel = i;

    for (; maxTravel < days.size() && days[maxTravel] < days[i] + 30; maxTravel++)
        ;
    ans = min(ans, cost[2] + solve(maxTravel, days, cost, dp));

    return dp[i] = ans;
}

int solveTab(int &n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n + 1, INT_MAX);

    // base case
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {
        // 1 day pass
        int ans = cost[0] + dp[k + 1];

        // 7 day pass
        int maxTravel = k;

        for (; maxTravel < days.size() && days[maxTravel] < days[k] + 7; maxTravel++)
            ;
        ans = min(ans, cost[1] + dp[maxTravel]);

        // 30 day pass
        maxTravel = k;

        for (; maxTravel < days.size() && days[maxTravel] < days[k] + 30; maxTravel++)
            ;
        ans = min(ans, cost[2] + dp[maxTravel]);

        dp[k] = ans;
    }

    return dp[0];
}

int solveTabSpaceOpt(int &n, vector<int> &days, vector<int> &cost)
{
    // day , cost till that day
    queue<pair<int, int>> month, week;

    // This solution has a space complexity of O(1) as at any instatnt in the monthly queue there will not be more than 30 elements and 7 in weekly.

    // Worst case
    // dayw were like 1,2,3.....
    // if we are at say 60th day, last day processed was 59
    // and max no of elements that can have day > 60 will be as 
    // 59+30, 58+30 ........... 31+30
    // ans all the expired days will be removed

    int ans = 0;

    for (int day : days)
    {
        // step 1 : remove expired days from both queue's
        while (!month.empty() && month.front().first + 30 <= day)
            month.pop();

        while (!week.empty() && week.front().first + 7 <= day)
            week.pop();

        // add current days cost
        week.push({day, ans + cost[1]});
        month.push({day, ans + cost[2]});

        // update ans
        //  why this
        //  since queue will have cost to travel on days > current day, so in given cost we can travel ahead

        ans += cost[0]; // 1 day ticket

        if (!week.empty())
            ans = min(ans, week.front().second);

        if (!month.empty())
            ans = min(ans, month.front().second);
    }

    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // vector<int> dp(367, -1);
    return solveTabSpaceOpt(n, days, cost);
}

int main()
{
    // Solution obj;

    vector<int> a = {4, 0, 8, 10, 5, 6};

    // cout << houseRobber(a);
    return 0;
}