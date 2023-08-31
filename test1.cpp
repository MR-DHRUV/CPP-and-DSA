#include <bits/stdc++.h>
using namespace std;

struct segmentNodes
{
    int low, high, data;
    segmentNodes *left, *right;
    segmentNodes(int low, int high, int data)
    {
        this->low = low;
        this->high = high;
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class RangeModule
{
    // unordered_map<long long int,int>seg;
    // as numbers are from 1 to 1e9 it will take more memory as compare to Tree - MLE WILL BE FIXED
    void updateRangeSeg(segmentNodes *root, int l, int r, int add)
    {
        if (root->low == l && root->high == r)
        {
            root->data = add;
            root->left = NULL;
            root->right = NULL;
            return;
        }

        int mid = root->low + (root->high - root->low) / 2;

        if (!root->left) // first time insertion of nodes
        {
            root->left = new segmentNodes(root->low, mid, root->data);
            root->right = new segmentNodes(mid + 1, root->high, root->data);
        }

        if (r <= mid)
            updateRangeSeg(root->left, l, r, add);
        else if (l > mid)
            updateRangeSeg(root->right, l, r, add);
        else
        {
            updateRangeSeg(root->left, l, mid, add);
            updateRangeSeg(root->right, mid + 1, r, add);
        }

        root->data = root->left->data && root->right->data;
    }

    bool QueryRangeSeg(segmentNodes *root, int l, int r) // just go to the interval using BS
    {
        if (!root->left) // leafNode
            return root->data;

        if (root->low == l && root->high == r)
            return root->data;

        int mid = root->low + (root->high - root->low) / 2;

        if (r <= mid)
            return QueryRangeSeg(root->left, l, r);
        else if (l > mid)
            return QueryRangeSeg(root->right, l, r);

        return QueryRangeSeg(root->left, l, mid) && QueryRangeSeg(root->right, mid + 1, r);
    }

public:
    segmentNodes *seg;
    RangeModule()
    {
        seg = new segmentNodes(0, 1e9, 0); // initially nothing is tracked
    }

    void addRange(int left, int right)
    {
        updateRangeSeg(seg, left, right - 1, 1);
    }

    bool queryRange(int left, int right)
    {
        return QueryRangeSeg(seg, left, right - 1);
    }

    void removeRange(int left, int right)
    {
        updateRangeSeg(seg, left, right - 1, 0);
    }
};

int main()
{

    return 0;
}