//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
    static bool compare(Job a, Job b)
    {
        return a.dead < b.dead;
    }

    void printMat(vector<vector<pair<int, int>>> arr)
    {
        cout << endl;

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j].second << " ";
            }
            cout << endl;
        }

        cout << endl;
    }

    pair<int, int> solve(int i, int time, Job arr[], int &n, vector<vector<pair<int, int>>> &dp)
    {
        if (i == n)
            return {0, 0};

        if (dp[i][time].second != -1)
            return dp[i][time];

        // either i will do this job or not
        pair<int, int> ans = solve(i + 1, time, arr, n, dp);
        pair<int, int> done = {0, 0};

        // dowing current job if possible
        if (arr[i].dead > time)
        {
            done = solve(i + 1, time + 1, arr, n, dp);
            done.first++;
            done.second += arr[i].profit;
            // cout<<done[0]<<" "<<done[1]<<" "<<ans[1]<<endl;
        }

        if (done.second > ans.second)
        {
            // cout<<"here 1"<<endl;
            return dp[i][time] = done;
        }

        return dp[i][time] = ans;
    }

    vector<int> solveGreedy(Job arr[], int &n)
    {
        sort(arr, arr + n, compare);

        priority_queue<int, vector<int>, greater<int>> minH;

        for (int i = 0; i < n; i++)
        {
            if (minH.size() < arr[i].dead)
            {
                minH.push(arr[i].profit);
            }
            else
            {
                if (arr[i].profit > minH.top())
                {
                    int diff = 1 + minH.size() - arr[i].dead;

                    priority_queue<int, vector<int>, greater<int>> temp = minH;
                    int tmp = 0;

                    while (diff != 0)
                    {
                        tmp += temp.top();
                        temp.pop();

                        diff--;
                    }

                    if (arr[i].profit > tmp)
                    {
                        temp.push(arr[i].profit);
                        minH = temp;
                    }
                }
            }
        }

        vector<int> ans = {(int)minH.size(), 0};

        while (!minH.empty())
        {
            ans[1] += minH.top();
            minH.pop();
        }

        return ans;
    }

public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // sorting jobs on the basis of deadline such that if two jobs are with same deadline then one with max profit is put first

        // vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n + 1, pair<int, int>(-1, -1)));

        return solveGreedy(arr, n);
    }
};
//{ Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends