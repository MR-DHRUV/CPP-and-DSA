#include <bits/stdc++.h>
using namespace std;

// User function template for C++

class Solution
{
    // count elements with given a and d
    int countEle(int i, int d, int A[])
    {
        if (i < 0)
            return 0;

        int ans = 0;

        for (int j = i - 1; j >= 0; j--)
        {
            if (A[i] - A[j] == d)
            {
                ans++;
                i = j;
            }
        }

        return ans;
    }

    // int optimized brute force
    int optBrute(int A[], int n)
    {
        if (n <= 2)
            return n;

        // fix 2 elements to make a and d
        int ans = 0;

        // unordered_map<int, int> dp[n + 1];

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans = max(ans, 2 + countEle(i, A[j] - A[i], A));
            }
        }

        return ans;
    }

public:
    int lengthOfLongestAP(int A[], int n)
    {
        return optBrute(A, n);
    }
};

int main()
{

    return 0;
}