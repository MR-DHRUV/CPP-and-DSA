#include <bits/stdc++.h>
using namespace std;

// This leads to MLE as we are tracking nodes in range 0->1e9
// class SegTree
// {
//     unordered_map<int, int> seg, lazy;
//     const int size = 1e9;

//     void merge(int idx, int low, int high)
//     {
//         if (lazy[idx] != 0)
//         {
//             seg[idx] = lazy[idx] == -1 ? 0 : (high - low + 1);

//             if (low != high)
//             {
//                 // propagate down
//                 lazy[2 * idx + 1] = lazy[idx];
//                 lazy[2 * idx + 2] = lazy[idx];
//             }

//             lazy[idx] = 0;
//         }
//     }

//     void updateHelper(int idx, int low, int high, int &l, int &r, int &val)
//     {
//         merge(idx, low, high);

//         // no overlap
//         if (r < low || l > high)
//             return;

//         // complete overlap
//         if (low >= l && high <= r)
//         {
//             lazy[idx] = val;
//             merge(idx, low, high);
//             return;
//         }

//         // partial overlap
//         int m = (low + high) / 2;
//         updateHelper(2 * idx + 1, low, m, l, r, val);
//         updateHelper(2 * idx + 2, m + 1, high, l, r, val);

//         // simple sum
//         seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
//     }

//     int query(int idx, int low, int high, int &l, int &r)
//     {
//         merge(idx, low, high);

//         if (r < low || l > high)
//             return 0;

//         if (low >= l && high <= r)
//             return seg[idx];

//         int m = (low + high) / 2;

//         int left = query(2 * idx + 1, low, m, l, r);
//         int right = query(2 * idx + 2, m + 1, high, l, r);

//         return left + right;
//     }

// public:
//     void updateRange(int l, int r, int val)
//     {
//         int v = val == 0 ? -1 : 1;
//         updateHelper(0, 0, size, l, r, v);
//     }

//     int rangeSum(int left, int right)
//     {
//         return query(0, 0, size, left, right);
//     }
// };

// class RangeModule
// {
//     SegTree *st;

// public:
//     RangeModule()
//     {
//         st = new SegTree;
//     }

//     void addRange(int left, int right)
//     {
//         // [ l, r - 1 ]->1
//         st->updateRange(left - 1, right - 2, 1);
//     }

//     bool queryRange(int left, int right)
//     {
//         // return sum[l, r - 1] == (right - left)
//         int sum = st->rangeSum(left - 1, right - 2);
//         // cout<<left<<" "<<right<<" "<<sum<<endl;
//         return sum == (right - left);
//     }

//     void removeRange(int left, int right)
//     {
//         // [ l, r - 1 ]->0
//         st->updateRange(left - 1, right - 2, 0);
//     }
// };

// to fix the MLE, we will now create a dynamic tree in heap

class Node
{
public:
    int low, high, data;
    Node *left, *right;

    Node(int l, int h, int v) : low(l), high(h), data(v), left(NULL), right(NULL){};
};

class RangeModule
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
    RangeModule()
    {
        seg = new Node(0, 1e9, 0);
    }

    void addRange(int left, int right)
    {
        // [ l, r - 1 ]->1
        updateHelper(seg, left, right - 1, 1);
    }

    bool queryRange(int left, int right)
    {
        // return sum[l, r - 1] == (right - left)
        return queryHelper(seg, left, right - 1);
    }

    void removeRange(int left, int right)
    {
        // [ l, r - 1 ]->0
        updateHelper(seg, left, right - 1, 0);
    }
};

int main()
{
    return 0;
}