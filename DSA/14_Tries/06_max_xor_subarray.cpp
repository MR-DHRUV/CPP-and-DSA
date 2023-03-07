//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++


class TrieNode
{
public:
    TrieNode *children[2];

    TrieNode()
    {
        children[0] = NULL;
        children[1] = NULL;
    };

    bool containsKey(int i)
    {
        return children[i] != NULL;
    }

    TrieNode *get(int i)
    {
        return children[i];
    }

    void set(int i, TrieNode *s)
    {
        children[i] = s;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        // since we have no number initially
        root = new TrieNode();
    }

    void insert(int n)
    {
        TrieNode *temp = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;

            if (!temp->containsKey(bit))
            {
                // n will be the smallest number
                temp->set(bit, new TrieNode());
            }

            // updating the smallest number
            temp = temp->get(bit);
        }
    }

    int maxXor(int x)
    {
        TrieNode *temp = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (x >> i) & 1;

            // max xor ke lie converse bit honi chahiye
            int c = 1 - bit;

            if (temp->containsKey(c))
            {
                ans = ans | (1 << i);
                temp = temp->get(c);
            }
            else
            {
                temp = temp->get(bit);
            }
        }

        return ans;
    }
};

class Solution
{
public:
    int maxSubarrayXOR(int N, int arr[])
    {

        // load the prefix XORED array into trie
        // insert 0 first
        // get max xor of trie elements and current element, then insert it

        // Why ?
        // ans will be either from
        // a continues subarray starting from 0
        // a single element
        // or a continues subarray starting from somewhere in between

        // for a contunues subrray starting from 0
        // eg : 110011 is our ans , when we cross check it for max xor with our trie, 0 will return same 110011
        // as a^0 = a

        // for a single element
        // arr : 3 11 15
        // prefix arr : 3 8 7

        // when we'll look for 7 we'll have 3,8,0 in trie
        // wen we'll xor 7 with 8, it will again set the bits to make 15
        // its like removing some portion from a pirticular sub array and same will be followed for a continues subarray starting from somewhere in between where we will remove some part from it

        Trie *t = new Trie();
        t->insert(0);

        int ans = t->maxXor(arr[0]);
        t->insert(arr[0]);

        // prefix
        for (int i = 1; i < N; i++)
        {
            arr[i] = arr[i] ^ arr[i - 1];
            ans = max(t->maxXor(arr[i]), ans);
            t->insert(arr[i]);
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends