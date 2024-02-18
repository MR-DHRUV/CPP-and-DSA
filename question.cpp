class TrieNode
{
public:
    TrieNode *children[26];
    long long cnt = 0;
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    };

    long long insertAndCountPS(string &word)
    {
        TrieNode *temp = root;

        for (char &ch : word)
        {
            if (temp->children[ch - 'a'] == NULL)
                temp->children[ch - 'a'] = new TrieNode();

            temp->cnt++;
            temp = temp->children[ch - 'a'];
        }

        temp->cnt++;
        // cout<<word<<" "<<temp->cnt<<endl;

        return temp->cnt - 1;
    }
};

// intuition: We only have to  add palindrome words to trie

class Solution
{
public:
    long long countPrefixSuffixPairs(vector<string> &words)
    {
        Trie t;
        long long ans = 0;

        for (int i = words.size() - 1; i >= 0; i--)
            ans += max(0ll, t.insertAndCountPS(words[i]));

        return ans;
    }
};