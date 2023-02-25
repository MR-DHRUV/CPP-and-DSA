#include <bits/stdc++.h>
using namespace std;

// updating the trie as per question
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

        for (int i = 16; i >= 0; i--)
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

    int countNumsWithXORlessThan(int x, int limit)
    {
        TrieNode *temp = root;
        int count = 0;

        for (int i = 16; i >= 0; i--)
        {
            int bitX = (x >> i) & 1;
            int bitLim = (limit >> i) & 1;

            // agar limit ki bit 0 haii toh i cannot guarentee that i will find numbers smaller than limit in that 0's path so process further
            if (bitLim == 0)
            {
                // now i need to follow the path of bitX so that same bits are xored to yeild 0

                if (temp->containsKey(bitX))
                {
                    temp = temp->get(bitX);
                    continue;
                }
                else
                {
                    return count; // XOR large aara haii
                }
            }

            // now its 1, now we can include all the numbers that yeild 0 at ith place
            if (temp->containsKey(bitX))
            {
                TrieNode *t = temp->get(bitX);
                count += t->prefixCount;
            }

            // point it to 1 to keep counting 1's
            // for current bit to be 1 check ahead that XOR must not exceed limit

            if (temp->containsKey(1 - bitX))
            {
                temp = temp->get(1 - bitX);
            }
            else
            {
                return count;
            }
        }

        return count;
    }
};

class Solution
{
public:
    int countPairs(vector<int> &nums, int low, int high)
    {
        Trie *t = new Trie();
        // initially insert isilie nahi kara as duplicates ho jayenge
        // if (a,b) E ans then (b,a) will also thus it will be counted twice

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += t->countNumsWithXORlessThan(nums[i], high + 1) - t->countNumsWithXORlessThan(nums[i], low);
            t->insert(nums[i]);
        }

        return ans;
    }
};

int main()
{

    Solution obj;
    vector<int> v = {3, 10, 5, 25, 2, 8};

    // cout << obj.findMaximumXOR(v);
    return 0;
}

/*
[536870912,0,534710168,330218644,142254206]
[[558240772,1000000000],[307628050,1000000000],[3319300,1000000000],[2751604,683297522],[214004,404207941]]

*/