#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    int childCount;

    TrieNode *children[26];
    bool isTerminal;

    // constructors
    TrieNode(){};
    TrieNode(char ch) : data(ch), isTerminal(false), childCount(0)
    {
        // init children with NULL
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    };
    TrieNode(char ch, bool terminal) : data(ch), isTerminal(terminal), childCount(0)
    {
        // init children with NULL
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    };
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    };

    void insert(string word);
    bool search(string word);
    void del(string word);
};

void insertRec(TrieNode *root, string s)
{
    if (s.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    int index = s[0] - 'a';

    TrieNode *child;

    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        child = new TrieNode(s[0]);
        root->children[index] = child;
        root->childCount++;
    }

    insertRec(child, s.substr(1));
}

void Trie::insert(string word)
{
    insertRec(root, word);
}

void delRec(TrieNode *root, string s)
{
    if (s.length() == 0)
    {
        root->isTerminal = false;
        return;
    }

    int index = s[0] - 'a';

    TrieNode *child = root->children[index];

    if (child == NULL)
    {
        return;
    }

    return delRec(child, s.substr(1));
}

void Trie::del(string word)
{
    delRec(root, word);
}

bool searchRec(TrieNode *root, string s)
{
    if (s.length() == 0)
    {
        return root->isTerminal;
    }

    int index = s[0] - 'a';

    TrieNode *child = root->children[index];

    if (child == NULL)
    {
        return false;
    }

    return searchRec(child, s.substr(1));
}

bool Trie::search(string word)
{
    return searchRec(root, word);
}

string longestCommonPrefix(vector<string> &arr, int n)
{
    // using trie
    // jis node ke 1 se jhyada child haii waha terminate krdo search ya koi terminal node mil gaya toh

    string ans;
    Trie t;

    // insert all words into trie
    for (int j = 0; j < n; j++)
    {
        t.insert(arr[j]);
    }

    // iterate trie
    TrieNode *root = t.root;

    while (root != NULL)
    {
        // terminal node haii ya no of children are not 1
        if (root->childCount != 1 || root->isTerminal)
        {
            break;
        }
        else
        {
            // find that children and construct prefix
            for (int i = 0; i < 26; i++)
            {
                if (root->children[i] != NULL)
                {
                    ans.push_back(root->children[i]->data);
                    root = root->children[i];
                    break;
                }
            }
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<string> s = {"abc", "abcd", "abcdef"};
    cout << longestCommonPrefix(s, 3);

    return 0;
}
