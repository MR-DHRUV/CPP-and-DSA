//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
        height = 1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
    if (!n)
        return 1;
    if (n->data <= lower || n->data >= upper)
        return 0;
    return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper);
}

pair<int, bool> isBalanced(Node *n)
{
    if (!n)
        return pair<int, bool>(0, 1);

    pair<int, bool> l = isBalanced(n->left);
    pair<int, bool> r = isBalanced(n->right);

    if (abs(l.first - r.first) > 1)
        return pair<int, bool>(0, 0);

    return pair<int, bool>(1 + max(l.first, r.first), l.second && r.second);
}

bool isBalancedBST(Node *root)
{
    if (!isBST(root, INT_MIN, INT_MAX))
        cout << "BST voilated, inorder traversal : ";

    else if (!isBalanced(root).second)
        cout << "Unbalanced BST, inorder traversal : ";

    else
        return 1;
    return 0;
}

void printInorder(Node *n)
{
    if (!n)
        return;
    printInorder(n->left);
    cout << n->data << " ";
    printInorder(n->right);
}

// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
        height = 1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
    if (!n)
        return 1;
    if (n->data <= lower || n->data >= upper)
        return 0;
    return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper);
}

pair<int, bool> isBalanced(Node *n)
{
    if (!n)
        return pair<int, bool>(0, 1);

    pair<int, bool> l = isBalanced(n->left);
    pair<int, bool> r = isBalanced(n->right);

    if (abs(l.first - r.first) > 1)
        return pair<int, bool>(0, 0);

    return pair<int, bool>(1 + max(l.first, r.first), l.second && r.second);
}

bool isBalancedBST(Node *root)
{
    if (!isBST(root, INT_MIN, INT_MAX))
        cout << "BST voilated, inorder traversal : ";

    else if (!isBalanced(root).second)
        cout << "Unbalanced BST, inorder traversal : ";

    else
        return 1;
    return 0;
}

void printInorder(Node *n)
{
    if (!n)
        return;
    printInorder(n->left);
    cout << n->data << " ";
    printInorder(n->right);
}

// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

Node *root;

int NodeHeight(Node *p)
{
    int hl;
    int hr;

    hl = (p && p->left) ? p->left->height : 0;
    hr = (p && p->right) ? p->right->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(Node *p)
{
    int hl;
    int hr;

    hl = (p && p->left) ? p->left->height : 0;
    hr = (p && p->right) ? p->right->height : 0;

    return hl - hr;
}

Node *LLRotation(Node *root)
{
    Node *pl = root->left;
    Node *plr = pl->right;

    pl->right = root;
    root->left = plr;

    // Update height
    root->height = NodeHeight(root);
    pl->height = NodeHeight(pl);

    // Update root
    if (root == root)
    {
        root = pl;
    }
    return pl;
}

Node *RRRotation(Node *p)
{
    Node *b = p->right;
    Node *prl = b->left;

    b->left = p;
    p->right = prl;

    // Update height
    p->height = NodeHeight(p);
    b->height = NodeHeight(b);

    // Update root
    if (root == p)
    {
        root = b;
    }
    return b;
}

Node *LRRotation(Node *p)
{
    Node *b = p->left;
    Node *c = b->right;

    b->right = c->left;
    p->left = c->right;

    c->left = b;
    c->right = p;

    // Update height
    b->height = NodeHeight(b);
    p->height = NodeHeight(p);
    c->height = NodeHeight(c);

    // Update root
    if (p == root)
    {
        root = c;
    }
    return c;
}

Node *RLRotation(Node *p)
{
    Node *b = p->right;
    Node *c = b->left;

    b->left = c->right;
    p->right = c->left;

    c->right = b;
    c->left = p;

    // Update height
    b->height = NodeHeight(b);
    p->height = NodeHeight(p);
    c->height = NodeHeight(c);

    // Update root
    if (root == p)
    {
        root = c;
    }
    return c;
}

Node *rInsert(Node *p, int key)
{
    Node *t;
    if (p == nullptr)
    {
        t = new Node(key);
        t->data = key;
        t->left = nullptr;
        t->right = nullptr;
        t->height = 1; // Starting height from 1 onwards instead of 0
        return t;
    }

    if (key < p->data)
    {
        p->left = rInsert(p->left, key);
    }
    else if (key > p->data)
    {
        p->right = rInsert(p->right, key);
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 1)
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == -1)
    {
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == -1)
    {
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == 1)
    {
        return RLRotation(p);
    }

    return p;
}

class Solution
{
public:
    /*You are required to complete this method */
    Node *insertToAVL(Node *node, int data)
    {
        // Your code here
        root = node;
        rInsert(node, data);

        return root;
    }
};

//{ Driver Code Starts.

int main()
{
    int ip[MAXN];

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> ip[i];

        Node *root = NULL;
        Solution obj;
        for (int i = 0; i < n; i++)
        {
            root = obj.insertToAVL(root, ip[i]);

            if (!isBalancedBST(root))
                break;
        }

        printInorder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

class Solution
{
public:
    /*You are required to complete this method */
    Node *insertToAVL(Node *node, int data)
    {
        // Your code here
    }
};

//{ Driver Code Starts.

int main()
{
    int ip[MAXN];

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> ip[i];

        Node *root = NULL;
        Solution obj;
        for (int i = 0; i < n; i++)
        {
            root = obj.insertToAVL(root, ip[i]);

            if (!isBalancedBST(root))
                break;
        }

        printInorder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends