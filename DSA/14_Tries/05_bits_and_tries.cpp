#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    // each node can have
    TrieNode *children[2];

    bool containsKey(int bit)
    {
        return children[bit] != NULL;
    }

    TrieNode *get(int bit)
    {
        return children[bit];
    }

    void set(int bit, TrieNode *s)
    {
        children[bit] = s;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    };

    // inserting a numbver bitwise into trie
    void insert(int x)
    {
        // starting from most significant bit (MSB)
        TrieNode *t = root;

        for (int i = 31; i >= 0; i--)
        {
            // obtaining the bit
            int bit = (x >> i) & 1;

            // inserting it into trie
            if (t->containsKey(bit) == false)
            {
                t->set(bit, new TrieNode());
            }
            t = t->get(bit);
        }
    }

    // O(32) = O(1)
    int getMax(int num)
    {
        TrieNode *t = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--)
        {
            // find ith bit of num
            int bit = (num >> i) & 1;

            // for max we need converse bit
            int c = 1 - bit;

            // if we have converse bit then we can set that bit in ans
            if (t->containsKey(c))
            {
                // is lsb wale 1 ko ith index pr pohuncha diya
                ans = ans | (1 << i);
                t = t->get(c);
            }
            else
            {
                // we dont have to make that bit 0 as wo pahle se hi 0 haii
                t = t->get(bit);
            }
        }

        return ans;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie *t = new Trie();

    // loading array 1 into trie
    for (int i = 0; i < arr1.size(); i++)
    {
        t->insert(arr1[i]);
    }

    int ans = 0;

    for (int i = 0; i < arr2.size(); i++)
    {
        ans = max(ans, t->getMax(arr2[i]));
    }

    return ans;
}

int main()
{
    // 9 -> 1001
    // in computer 0000......1001 ie either 32 or 64 bits

    // XOR related problems
    // we are given an array of numbers ans a number x, we have to find the max value of arr[i]^x

    // Approach
    // step 1 : insert all the numbers into the trie in binary format with 32/64 bits starting from msb
    // step 2 : find maximum no that we can possibly make

    // eg we x = 10000101
    // for 1 we will find 0 if not found no other option we have to take 1 only
    // for 0 we will find 1 as 1^0 = 1
    // repreat the process for all bits
    // we''ll start from msb as if we could set msb our ans will be max
    // Time Complexity : O(32*N)

    // if we have 2 arrays ans need to find max xor
    // 1 ko trie me daaldo
    // 2 nd ke keys 1-1 kerke check krlo
    // return max value found

    return 0;
}