//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
    // Complete the function and return minimum number of operations
public:
    int specialPalindrome(string s1, string s2)
    {

        int ans = INT_MAX;
        int n = s1.size() - 1;
        int m = s1.size();

        // brute force solution
        for (int i = 0; i < s1.length(); i++)
        {
            // copy s2 at index i
            string temp = s1;
            int cnt = 0;
            bool isPossible = true;

            for (int j = 0; j < s2.length(); j++)
            {
                if (temp[i + j] == s2[j])
                {
                    continue;
                }
                else
                {
                    cnt++;
                    temp[i + j] = s2[j];
                }
            }

            // checking if we can make it palindrome

            for (int j = 0; j < temp.length() / 2; j++)
            {
                if (temp[j] == temp[n - j])
                {
                    continue;
                }

                // if j and n-j both are parts of s2 we cant make our string so it will be -1 as paer current situation
                if (j >= i && j <= (i + s2.length()) && (n - j) >= i && (n - j) <= (i + s2.length()))
                {
                    isPossible = false;
                    break;
                }

                // convert possible one
                cnt++;
            }

            if (isPossible)
            {
                ans = min(ans, cnt);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1, s2);

        cout << ans << endl;
    }
}
// } Driver Code Ends