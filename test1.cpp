#include <bits/stdc++.h>
using namespace std;

// updating trie to get the index of any word in original array
typedef struct TrieNode
{
    TrieNode *children[26];
    int index = -1;
    vector<int> list;
}TrieNode;

class Solution
{
    TrieNode *root;

    // checks whether a string is palindrome or not in the given range
    bool isPalindrome(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }

        return true;
    }

    // inserting in reverse order
    void insert(string s, int idx)
    {
        TrieNode *temp = root;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (temp->children[s[i] - 'a'] == NULL)
            {
                temp->children[s[i] - 'a'] = new TrieNode();
            }

            // checking if itna part palindrome h ya nahi
            if (isPalindrome(s, 0, i))
            {
                // if yes then
                temp->list.push_back(idx);
            }

            temp = temp->children[s[i] - 'a'];
        }

        // we have added idx in the list of last node as a single character is palindrome
        // last node me isilie add hua kyuki reverse string store kr rhe
        temp->list.push_back(idx);

        // set index
        temp->index = idx;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {

        // approach : store the words in reverse order in trie to be able to add them as prefix
        root = new TrieNode();
        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); i++)
        {
            insert(words[i], i);
        }

        for (int i = 0; i < words.size(); i++)
        {
            TrieNode *temp = root;
            string &s = words[i];

            for (int j = 0; j < s.length(); j++)
            {

                // if current node is a terminal of some other word and

                // this condition is for generating pairs of the form
                // s -> s1 + s2
                // s1 s2 s1 where s2 is palindrome in itself we have found its counter part which was not palindrome
                // like we have sll and we found s , 1->n palindrome in itself, 0 ka counter part mil gaya
                // thus pair is of the form idx, temp->index
                if (temp->index != -1 && temp->index != i && isPalindrome(s, j, s.length() - 1))
                {
                    ans.push_back({i, temp->index});
                }

                temp = temp->children[s[j] - 'a'];
                if (temp == NULL)
                {
                    break;
                }
            }

            if (temp == NULL)
            {
                continue;
            }

            // this for loop is for generating pairs which from palindromic words of the form
            // s_{some part of other string that is palindromic}_s
            // s_p_s where p can be NULL too and p_s is one word
            // eg :  abcd_dcba, lls_ss_sll (sssll is one word)
            for (int j : temp->list)
            {
                if (j == i)
                    continue;
                ans.push_back({i, j});
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
    vector<vector<int>> v = obj.palindromePairs(words);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}