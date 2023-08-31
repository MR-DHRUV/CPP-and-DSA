#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int low, high, data;
    Node *left, *right;

    Node(int l, int h, int v) : low(l), high(h), data(v), left(NULL), right(NULL){};
};

class DynamicSegTree
{
    Node *seg;

    void updateHelper(Node *root, int l, int r, int val)
    {
        if (root->low == l && root->high == r)
        {
            // maine ek range ko change krdia toh uske neeche ke sab decendants bhi ab curr ko follow krenge isilie left aur right child null krdia
            root->data = val;
            root->left = NULL;
            root->right = NULL;
            return;
        }

        int mid = root->low + (root->high - root->low) / 2;

        // first time insertion
        if (!root->left)
        {
            root->left = new Node(root->low, mid, root->data);
            root->right = new Node(mid + 1, root->high, root->data);
        }

        // now its just like you traverse a bst, left jana haii ya right
        // ya dono partialy jana h

        if (r <= mid)
            updateHelper(root->left, l, r, val);
        else if (l > mid)
            updateHelper(root->right, l, r, val);
        else
        {
            // left wale part me yaha tk ka daya h
            updateHelper(root->left, l, mid, val);
            updateHelper(root->right, mid + 1, r, val);
        }

        // now for current node the data will be 1 iff both left and right will be 1, as it will mark that all of its children are baing tracked

        root->data = root->left->data && root->right->data;
    }

    bool queryHelper(Node *root, int l, int r)
    {
        // decendants ka data nahi haii toh jo current range ka ans h wohi unka haii
        if (!root->left)
            return root->data;

        // complete overlap
        if (root->low == l && root->high == r)
            return root->data;

        int mid = root->low + (root->high - root->low) / 2;

        if (r <= mid)
            return queryHelper(root->left, l, r);
        else if (l > mid)
            return queryHelper(root->right, l, r);

        return queryHelper(root->left, l, mid) && queryHelper(root->right, mid + 1, r);
    }

public:
    DynamicSegTree()
    {
        seg = new Node(0, 1e9, 0); // only a single node with 0 value, to represent nothing is being tracked.
    }

    void update(int l, int r, int val)
    {
        updateHelper(seg, l, r, val);
    }

    bool query(int l, int r)
    {
        return queryHelper(seg, l, r);
    }
};

int main()
{

    return 0;
}