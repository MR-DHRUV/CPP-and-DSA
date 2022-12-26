#include <bits/stdc++.h>
using namespace std;

/************************************************************

    Following is the TreeNode class structure:
************************************************************/
template <class T>
class TreeNode
{
public:
    T data;
    int height;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int getHeight(TreeNode<int> *root)
{
    int hl = root && root->left ? root->left->height : 0;
    int hr = root && root->right ? root->right->height : 0;

    return max(hl, hr) + 1;
}

int getBalanceFactor(TreeNode<int> *root)
{
    int hl = root && root->left ? root->left->height : 0;
    int hr = root && root->right ? root->right->height : 0;

    return hl - hr;
}


TreeNode<int> *LLRotation(TreeNode<int> *root)
{
    TreeNode<int> *b = root->left;

    // b's children
    TreeNode<int> *br = b->right;

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

TreeNode<int> *LRRotation(TreeNode<int> *root)
{
    // root->left
    TreeNode<int> *b = root->left;

    // root->left->right
    TreeNode<int> *c = b->right;

    // c's children
    TreeNode<int> *cl = c->left;
    TreeNode<int> *cr = c->right;

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

TreeNode<int> *RLRotation(TreeNode<int> *root)
{
    // root->right
    TreeNode<int> *b = root->right;

    // root->right->left
    TreeNode<int> *c = b->left;

    // c's children
    TreeNode<int> *cl = c->left;
    TreeNode<int> *cr = c->right;

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

TreeNode<int> *RRRotation(TreeNode<int> *root)
{
    // root->right
    TreeNode<int> *b = root->right;

    // b's left children
    TreeNode<int> *bl = b->left;

    // changing links
    b->left = root;

    // placing b's children
    root->right = bl;

    // changing heights
    root->height = getHeight(root);
    b->height = getHeight(b);

    return b;
}

TreeNode<int> *rInsert(TreeNode<int> *root, int e)
{
    // base case
    if (root == NULL)
    {
        // leaf node is always at height 1
        TreeNode<int> *t = new TreeNode<int>(e);
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

TreeNode<int> *insertionInAvlTree(vector<int> &allNodeValues, int n)
{
    TreeNode<int> *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = rInsert(root, allNodeValues[i]);
    }

    return root;
}
