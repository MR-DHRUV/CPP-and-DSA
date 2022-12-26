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

int getHeight(Node *root)
{
    int hl = (root && root->left) ? root->left->height : 0;
    int hr = (root && root->right) ? root->right->height : 0;

    return max(hl, hr) + 1;
}

int getBalanceFactor(Node *root)
{
    int hl = (root && root->left) ? root->left->height : 0;
    int hr = (root && root->right) ? root->right->height : 0;

    return hl - hr;
}

Node *LLRotation(Node *root)
{
    Node *b = root->left;

    // b's children
    Node *br = b->right;

    // changing links
    b->right = root;

    // placing b's children
    root->left = br;

    // changing heights
    root->height = getHeight(root);
    b->height = getHeight(b);

    // now b will be the new root
    return b;
}

Node *LRRotation(Node *root)
{
    // root->left
    Node *b = root->left;

    // root->left->right
    Node *c = b->right;

    // c's children
    Node *cl = c->left;
    Node *cr = c->right;

    // changing links
    c->left = b;
    c->right = root;

    // placing c's children
    b->right = cl;
    root->left = cr;

    // changing heights
    b->height = getHeight(b);
    root->height = getHeight(root);
    c->height = getHeight(c);

    return c;
}

Node *RLRotation(Node *root)
{
    // root->right
    Node *b = root->right;

    // root->right->left
    Node *c = b->left;

    // c's children
    Node *cl = c->left;
    Node *cr = c->right;

    // changing links
    c->right = b;
    c->left = root;

    // placing c's children
    b->left = cr;
    root->right = cl;

    // changing heights
    b->height = getHeight(b);
    root->height = getHeight(root);
    c->height = getHeight(c);

    return c;
}

Node *RRRotation(Node *root)
{
    // root->right
    Node *b = root->right;

    // b's left children
    Node *bl = b->left;

    // changing links
    b->left = root;

    // placing b's children
    root->right = bl;

    // changing heights
    root->height = getHeight(root);
    b->height = getHeight(b);

    return b;
}

Node *rInsert(Node *root, int e)
{
    // base case
    if (root == NULL)
    {
        // leaf node is always at height 1
        Node *t = new Node(e);
        t->height = 1;
        return t;
    }

    // finding and inserting the node : O(logN)
    if (root->data > e)
    {
        root->left = rInsert(root->left, e);
    }
    else if (root->data < e)
    {
        root->right = rInsert(root->right, e);
    }

    // now at returning time of every call we'll update the height of whole path that is followed
    // O(1)
    root->height = getHeight(root);

    // now checking if the node is balanced or not
    // Rotaion complexity : O(1)

    // case 1 : LL
    if (getBalanceFactor(root) == 2 && getBalanceFactor(root->left) == 1)
    {
        return LLRotation(root);
    }
    // case 2 : LR
    else if (getBalanceFactor(root) == 2 && getBalanceFactor(root->left) == -1)
    {
        return LRRotation(root);
    }
    // case 3 : RL
    else if (getBalanceFactor(root) == -2 && getBalanceFactor(root->right) == 1)
    {
        return RLRotation(root);
    }
    // case 4 : RR
    else if (getBalanceFactor(root) == -2 && getBalanceFactor(root->right) == -1)
    {
        return RRRotation(root);
    }

    return root;
}

class Solution
{
public:
    /*You are required to complete this method */
    Node *insertToAVL(Node *node, int data)
    {
        node = rInsert(node, data);
        return node;
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