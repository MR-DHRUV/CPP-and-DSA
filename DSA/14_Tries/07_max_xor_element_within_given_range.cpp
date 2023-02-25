#include <bits/stdc++.h>
using namespace std;

// incredible solution : iske lie jo kharid na ho lelio 

// updating the trie as per question
class TrieNode
{
public:
    TrieNode *children[2];
    int smallest; // smallest number that we can find on this path

    TrieNode(int n)
    {
        smallest = n;
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
        root = new TrieNode(-1);
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
                temp->set(bit, new TrieNode(n));
            }

            // updating the smallest number
            temp = temp->get(bit);
            temp->smallest = min(temp->smallest, n);
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

    int maxXorWithLimit(int x, int limit)
    {
        TrieNode *temp = root;
        int ans = 0;
        int num = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (x >> i) & 1;

            // max xor ke lie converse bit honi chahiye
            int c = 1 - bit;

            // initial check

            if (temp->containsKey(c))
            {
                // inital check ki iss path pr jana haii ya nahi
                TrieNode *v = temp->get(c);

                if (v->smallest <= limit)
                {
                    int newNum = num | (c << i);

                    if (newNum <= limit)
                    {
                        num = newNum;
                        ans = ans | (1 << i);
                        temp = temp->get(c);
                    }

                    // greater haii , we need bit 0
                    else
                    {
                        // 0 bit not present thus, smaller number dosent exist
                        if (temp->containsKey(0) == false)
                        {
                            cout << "r1" << endl;
                            return -1;
                        }

                        // now we have bit 0
                        temp = temp->get(0);
                    }
                }
                else
                {
                    if (temp->containsKey(0))
                    {
                        v = temp->get(0);

                        if (v->smallest <= limit)
                        {
                            temp = temp->get(0);
                        }
                        else
                        {
                            return -1;
                        }
                    }
                    else
                    {
                        return -1;
                    }
                }
            }
            else
            {
                // we dont h converse bit, thus no change in the answer

                // for sure, we'll have bit as we dont have c
                int newNum = num | (bit << i);

                if (newNum <= limit)
                {
                    num = newNum;
                    temp = temp->get(bit);
                }

                // greater haii
                else
                {
                    return -1;
                }
            }
        }

        return ans;
    }
    
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {

        Trie *t = new Trie();

        // loading nums into trie
        for (int i = 0; i < nums.size(); i++)
        {
            t->insert(nums[i]);
        }

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++)
        {
            ans.push_back(t->maxXorWithLimit(queries[i][0], queries[i][1]));
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