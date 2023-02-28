#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[10];
};

class Trie
{
    TrieNode *root;
    vector<int> ans;

public:
    Trie()
    {
        root = new TrieNode();
    }

    // since any number will have a max length of 12-13 thus this process is of O(1) time complexity
    void insert(int num)
    {
        vector<int> temp;

        while (num > 0)
        {
            temp.push_back(num % 10);
            num /= 10;
        }

        TrieNode *curr = root;

        for (int i = temp.size() - 1; i >= 0; i--)
        {
            if (curr->children[temp[i]] == NULL)
            {
                curr->children[temp[i]] = new TrieNode();
            }

            curr = curr->children[temp[i]];
        }
    }

    void solve(TrieNode *root, int num)
    {
        if (root == NULL)
        {
            return;
        }

        for (int i = 0; i <= 9; i++)
        {
            if (root->children[i] != NULL)
            {
                int temp = (num * 10) + i;
                ans.push_back(temp);
                solve(root->children[i], temp);
            }
        }
    }

    vector<int> lexiographicOrder()
    {
        ans.clear();
        solve(root, 0);
        return ans;
    }
};

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        // generate all the numbers starting from 1 less than equal to n in lexio graphic order and so on

        Trie *t = new Trie();

        for (int i = 1; i <= n; i++)
        {
            t->insert(i);
        }

        return t->lexiographicOrder();
    }
};

int main()
{

    return 0;
}