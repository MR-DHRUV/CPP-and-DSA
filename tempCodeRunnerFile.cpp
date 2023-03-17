//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{

    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j)
        {
            if (s[i++] == s[j--])
            {
                continue;
            }

            return false;
        }

        return true;
    }

    // Complete the function and return minimum number of operations
public:
    int specialPalindrome(string s1, string s2)
    {
        // base cases
        if (s2.length() > s1.length())
        {
            return -1;
        }

        if (s1.length() == s2.length())
        {
            if (s1 == s2 && isPalindrome(s1))
            {
                return 0;
            }

            return -1;
        }

        for (int i = 0; i < s2.length(); i++)
        {
            // hum s2 banana chah rahe haii s1 me starting from index i
            // locate the strting index if 0-> i-1 tak ka part present haii 

            // finding all the indeces that contains the s2 from 0 to i 

            for (int j = 0; j < s1.length(); j++)
            {
                
            }
            
        }
        


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