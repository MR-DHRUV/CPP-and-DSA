//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    string rearrange(string S, int N)
    {
        int v[5] = {0};
        int c[26] = {0};

        int vCount = 0;
        int cCount = 0;

        unordered_map<char,int> mp;
        mp['a'] = 0;
        mp['e'] = 1;
        mp['i'] = 2;
        mp['o'] = 3;
        mp['u'] = 4;

        unordered_map<int,char> pm;
        pm[0] = 'a';
        pm[1] = 'e';
        pm[2] = 'i';
        pm[3] = 'o';
        pm[4] = 'u';

        char smallChar = 'u';
        char smallVow = 'z';


        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u')
            {
                vCount++;
                v[mp[S[i]]]++;

                if(S[i] < smallVow)
                {
                    smallVow = S[i];
                }
            }
            else
            {
                cCount++;
                c[S[i]]++;

                if(S[i] < smallChar)
                {
                    smallChar = S[i];
                }
            }
        }

        int diff = abs(cCount - vCount);

        if (diff > 1)
        {
            return "-1";
        }

        int iter1;
        int iter2;

        if (vCount == cCount)
        {
            if (smallVow < smallChar)
            {
                iter1 = 0;
                iter2 = 1;
            }
            else
            {
                iter1 = 1;
                iter2 = 0;
            }
        }
        else if (vCount > cCount)
        {
            iter1 = 0;
            iter2 = 1;
        }
        else
        {
            iter1 = 1;
            iter2 = 0;
        }

        for(int i = 0 ; i < 5 ; i++)
        {
            int l = v[i];
            for (int k = 0; k < l; k++)
            {
                S[iter1] = (char)pm[i];
                iter1 = iter1+2;
            }
            
        }
        for(int i = 1 ; i < 26 ; i++)
        {
            int l = c[i];
            for (int k = 0; k < l; k++)
            {
                S[iter2] = char(i+'a');
                iter2 = iter2+2;
            }
            
        }

        return S;
    }
};


//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends