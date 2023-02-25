//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++



// updating the trie as per question to provide the ability to delete a number from it
class TrieNode
{
public:
    TrieNode *children[2];
    int prefixCount; // numbers that start with same binary representation

    TrieNode()
    {
        prefixCount = 0;
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

public:
    TrieNode *root;
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
            temp->prefixCount++;
        }
    }

    // no need to verify whether the no is present or not, it will be for sure
    void erase(int n)
    {
        // starting from MSB as usual

        TrieNode *temp = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            
            if(temp->children[bit] == NULL)
            {
                return;
            }

            // eraseing step
            if (temp->children[bit]->prefixCount == 1)
            {
               temp->children[bit] = NULL;
               return;
            }

            temp->prefixCount--; // for rest nodes

            // updating the pointer
            temp = temp->get(bit);
        }
    }

    int minXor(int x)
    {
        TrieNode *temp = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (x >> i) & 1;

            // min xor ke lie same bit honi chahiye

            if (temp->containsKey(bit))
            {
                temp = temp->get(bit);
            }
            else
            {
                // we have to make this bit as opposite
                ans = ans | (1 << i);
                temp = temp->get(1 - bit); // converse bit is only present
            }
        }

        return ans;
    }
};

class Solution
{
public:
    int minxorpair(int N, int arr[])
    {

        Trie *t = new Trie();

        for (int i = 0; i < N; i++)
        {
            t->insert(arr[i]);
        }

        // cout<<t->root->prefixCount<<endl;

        int ans = INT_MAX;

        for (int i = 0; i < arr[i]; i++)
        {
            t->erase(arr[i]);
            ans = min(ans, t->minXor(arr[i]));
            // cout<<ans<<endl;
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
        cout << ob.minxorpair(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends