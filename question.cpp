//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends



class Solution
{
    inline int multiply(char &a, char &b, int &c)
    {
        int a1 = a - '0';
        int b1 = b - '0';
        return a1 * b1 + c;
    }

    void add(string &a, string &b)
    {
        int lenA = a.size();
        int lenB = b.size();
        int carry = 0;
        string result;

        // Traverse the strings from right to left
        for (int i = lenA - 1, j = lenB - 1; i >= 0 || j >= 0 || carry > 0; i--, j--)
        {
            int numA = (i >= 0) ? (a[i] - '0') : 0;
            int numB = (j >= 0) ? (b[j] - '0') : 0;

            int sum = numA + numB + carry;
            carry = sum / 10;
            sum %= 10;

            result.push_back(char(sum + '0'));
        }

        reverse(result.begin(), result.end());

        a = result;
    }

public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2)
    {
        // simple multiple krna haii carry wala jaise bachpan me krte the
        string ans(max(s1.length(), s2.length()), '0');
        string g = "";

        for (int i = s2.length() - 1; i >= 0; i--)
        {
            string temp;
            int carry = 0;

            for (int j = s1.length() - 1; j >= 0; j--)
            {
                int m = multiply(s1[j], s2[i], carry);

                temp.push_back((m % 10) + '0');
                carry = m / 10;

                // cout<<s1[j]<<" "<<s2[i]<<" "<<m<<" "<<carry<<endl;
            }

            if (carry > 0)
                temp.push_back(carry + '0');

            reverse(temp.begin(), temp.end());
            temp.append(g.begin(), g.end());

            // add this to answer
            add(ans, temp);

            // add gap
            g += "0";
        }

        // remove leading zeros from answer
        int i =0;
        while (i < ans.length() && ans[i] == 0)
        {
            i++;
        }

        return ans.substr(i);
    }
};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends