//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    const int mod = 1e9 + 7;
    int dp[101][27][27][2];

    int solve(int i, int last, int secondLast, bool greater, string &S)
    {
        // if all characters are used and its larger
        if (i == S.length())
            return greater;

        if (dp[i][last][secondLast][greater] != -1)
            return dp[i][last][secondLast][greater];

        int curr = S[i] - 'a', ans = 0;

        // agar last char bada tha toh I can start with a
        if (greater)
            curr = 0;

        for (int j = curr; j < 26; j++)
        {
            if (j != last && j != secondLast)
                ans = (ans + solve(i + 1, j, last, (greater | j > curr), S)) % mod;
        }

        return dp[i][last][secondLast][greater] = ans;
    }

public:
    int specialStrings(int N, string S)
    {
        // wohi dp with brute force haii
        // but here we will make string in an intelliget way

        // 1 we will only make string that are strictly greater than current string
        // 2 which are speical
        // special string are those whose all substr of len >= 2 are not palindrome
        // toh we just have to ensure adjacnet and alternating chars are not same
        // aba aa this pattern should not occur

        memset(dp, -1, sizeof(dp));
        return solve(0, 26, 26, 0, S);
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        string S;
        cin >> N >> S;
        Solution ob;
        cout << ob.specialStrings(N, S) << "\n";
    }
    return 0;
}
// } Driver Code Ends