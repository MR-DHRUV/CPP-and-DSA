#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // ans = size - lis

        // start is fixed in assending order just find lis based on end upon the condition
        // curr.start >= last.end

        vector<int> inc;
        sort(intervals.begin(), intervals.end());

        for (auto v : intervals)
        {
            // find on the basis of start
            // here we are using upper bound as we need to find a end vallue that is strictly greater than current start
            int idx = upper_bound(inc.begin(), inc.end(), v[0]) - inc.begin();

            if (idx == inc.size())
            {
                inc.push_back(v[1]); // push end
            }
            else
            {
                // we are keeping min value as we can include some other interval that has a greater start
                // using min simple means that exclude the pair if it has a large ending point and it can be included as it has a small start that overlaps with some other end points
                inc[idx] = min(inc[idx], v[1]);
            }
        }

        return intervals.size() - inc.size();
    }

    // sort on the basis of ending values
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

    int eraseOverlapIntervalsFast(vector<vector<int>> &intervals)
    {
        // sorting based solutions

        vector<int> inc;
        sort(intervals.begin(), intervals.end(), compare);

        int ans = 1;
        int prev = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= prev)
            {
                ans++;
                prev = intervals[i][1];
            }
        }

        return intervals.size() - ans;
    }
};

int main()
{

    return 0;
}