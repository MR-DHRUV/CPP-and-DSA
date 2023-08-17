//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++



class Solution
{
    bool isPossibleToCarry(int num[], int n, int i, int j)
    {
        // odd case
        if(n%2 != 0)
        {
            if(i-1 == n/2 && num[i-1] == 9)
                return false;
            
            return true;    
        }
        // even case
        // i-1 is the second mid
        else
        {
            if(i-1 == n/2 && num[i-1] == 9 && num[i-2] == 9)
                return false;
        }
        
        return true;
    }
    
    
    
public:
    vector<int> generateNextPalindrome(int num[], int n)
    {
        // single number case
        if(n == 1)
        {
            if(num[0] < 9)
                return {num[0]+1};
            return {1,1};    
        }
        
        
        int i = n - 1, j = 0;
        int carry = 0;

        bool isAll9 = true;
        bool isPalin = true;
        
        // check palin and all 9
        while (i > j)
        {
            if (num[i] != num[j])
            {
                isPalin = false;
                isAll9 = false;
                break;
            }

            if (num[i] != 9)
                isAll9 = false;

            i--;
            j++;
        }

        // all 9 case
        if (isAll9)
        {
            vector<int> ans(n + 1, 0);
            ans[0] = ans[n] = 1;
            return ans;
        }

        // palindrome case
        if (isPalin)
        {
            int s, e;

            // try to incriment bit from middle
            if (n % 2 != 0)
            {
                s = e = n / 2;
            }
            else
            {
                e = (n/2);
                s = e-1;
            }

            while (s >= 0)
            {
                if (num[s] < 9)
                {
                    num[s]++;
                    
                    if(s != e)
                    {
                        num[e]++;
                        // make all nums in b/w as 0 
                        for (int k = s + 1; k < e; k++)
                            num[k] = 0;
                    }
                    
                    break;
                }
                s--; e++;
            }
        }
        else
        {
            // generic case
            i = n - 1, j = 0;
            while (i > j)
            {
                // carry addition
                num[i] += carry;
                carry = num[i] == 10 ? 1 : 0;
                num[i] %= 10;
                // cout<<num[i]<<" "<<num[j]<<endl;

                if (num[j] > num[i])
                {
                    num[i] = num[j];
                }
                else if (num[j] < num[i])
                {
                    // scope for carry
                    // only case we cant have carry is next element is middle one and is 9 and no of elemrnts are odd
                    if (i - 1 > j && isPossibleToCarry(num,n,i,j))
                    {
                        carry = 1;
                        num[i] = num[j];
                    }
                    else
                    {
                        // dont make j = i as that can be huge 
                        // juke make j = j+1 ans i = j
                        // which will ensunre the number formed is smallest
                        num[j]++;
                        num[i] = num[j];

                        // see here you have made incrimented nums j
                        // so we can make all 0's in range [j+1] [i-1]
                        for (int k = j + 1; k < i; k++)
                            num[k] = 0;
                    }
                }
                i--; j++;
            }
            
            // carry left check 
            if(carry)
            {
                num[i]++;
                
                if(i != j)  
                    num[j]++;
            }
                
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            ans.push_back(num[i]);
        }

        return ans;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends