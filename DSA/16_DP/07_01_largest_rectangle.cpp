#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev;
    prev = prevSmallerElement(heights, n);

    int area = 0;

    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = max(area, newArea);
    }

    return area;
}

// yeh largest area in a histogram se copy kara hua haii
// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        // same as largest area in a histogram
        // row by row hitogram banate jao ans nikalte jao

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> histogram(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            // updating the histogram
            for (int j = 0; j < m; j++)
            {
                // since current row base hogi toh if base me 0 aagaya then the height of current bar will be 0
                if (matrix[i][j] == '0')
                    histogram[j] = 0;
                else
                    histogram[j] += 1;
            }

            ans = max(ans, largestRectangleArea(histogram));
        }

        return ans;
    }
};

int main()
{

    return 0;
}