//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL){};
};

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
    void pre(Node *root, string code, vector<string> &ans)
    {
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(code);
            return;
        }

        pre(root->left, code + '0', ans);
        pre(root->right, code + '1', ans);
    }

public:
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        // huffman codes are used for compression of strings (loss less)
        // say a is represented as 10110101 in binary and the string is abs
        // so we have 3 different characters where we can say that a = 00, b = 01, c = 10 
        // we further try to compress the string in the folllowing way
        // eg : aaabdcs
        // first we merge the nodes with lower frequency as nodes merged first likely to have greated depth due to which the number of bits required to represent them will be more 
        // and these characters with large bits will be minimum  

        // building tree
        // tree is build such that ki we merge characters of minimum frequency every time and sum of their frequency is our new node
        // all characters are only present in leaf nodes

        // 

        priority_queue<Node *, vector<Node *>, Compare> minH;

        for (int num : f)
        {
            minH.push(new Node(num));
        }

        // build tree
        while (minH.size() > 1)
        {
            Node *lchild = minH.top();
            minH.pop();

            Node *rchild = minH.top();
            minH.pop();

            Node *head = new Node(lchild->data + rchild->data);
            head->left = lchild;
            head->right = rchild;

            minH.push(head);
        }

        Node *head = minH.top(); // head of tree

        vector<string> ans;
        pre(head, "", ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for (int i = 0; i < N; i++)
        {
            cin >> f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S, f, N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends