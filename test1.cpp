#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
	TrieNode *children[26];

	TrieNode()
	{
		for (int i = 0; i < 26; i++)
		{
			children[i] = NULL;
		}
	};

	TrieNode *get(char ch)
	{
		return children[ch - 'a'];
	}

	void set(char ch, TrieNode *t)
	{
		children[ch - 'a'] = t;
	}

	bool containsKey(char ch)
	{
		return (children[ch - 'a'] != NULL);
	}
};

int countDistinctSubstrings(string &s)
{
	// n2 complexity
	// why trie then, we could use hash map
	// trie optimises space complexity

	// trie approach
	// wee insert all substrings into trie and whenever we insert any letter that is not present in the trie we incriment our ans by 1

	TrieNode *root = new TrieNode();

	int ans = 0;
	int n = s.length();

	for (int i = 0; i < n; i++)
	{
		TrieNode *t = root;

		for (int j = i; j < n; j++)
		{
			// check if current character is present
			if (!t->containsKey(s[j]))
			{
				ans++;
				t->set(s[j], new TrieNode());
			}
			t = t->get(s[j]);
		}
	}

	// +1 for null string 
	return ans+1;
}

int main()
{

	return 0;
}