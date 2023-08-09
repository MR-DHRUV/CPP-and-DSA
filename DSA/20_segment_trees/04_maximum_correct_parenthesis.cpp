#include <bits/stdc++.h>
using namespace std;

// now, for this question we need to store data like, no of open brackets, closed brackets and full brackets for any range so we will create a segTee Ndoe

// intution
// no of full bracket = min(open from left, closing from right)
// why this work : as we need subsequence, so we can omit the redundant brackets

class Node
{
public:
    int open, closed, full;

    Node() : open(0), closed(0), full(0){};
    Node(int a, int b, int c) : open(a), closed(b), full(c){};
};

Node merge(Node left, Node right)
{
    int f = left.full + right.full + min(left.open, right.closed);
    int o = left.open + right.open - min(left.open, right.closed);
    int c = left.closed + right.closed - min(left.open, right.closed);

    return Node(o, c, f);
}

void build(int idx, int low, int high, string &str, Node seg[])
{
    if (low == high)
    {
        Node t;
        t.open = str[low] == '(';
        t.closed = str[low] == ')';
        t.full = 0;

        seg[idx] = t;
        return;
    }

    int m = (low + high) / 2;
    build((2 * idx) + 1, low, m, str, seg);
    build((2 * idx) + 2, m + 1, high, str, seg);

    // for current node
    Node left = seg[(2 * idx) + 1];
    Node right = seg[(2 * idx) + 2];

    seg[idx] = merge(left, right);
}

Node query(int idx, int low, int high, int &l, int &r, Node seg[])
{
    // complete overlap
    if (low >= l && high <= r)
        return seg[idx];

    // no overlap
    if (r < low || l > high)
        return Node();

    // partial overlap
    int mid = (low + high) / 2;

    Node left = query((2 * idx) + 1, low, mid, l, r, seg);
    Node right = query((2 * idx) + 2, mid + 1, high, l, r, seg);

    // total closed brackets will be
    return merge(left, right);
}

signed main()
{
#ifndef IO_FROM_FILE
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
#endif

    string s;
    getline(cin, s);

    Node seg[4 * s.length()];

    build(0, 0, s.length() - 1, s, seg);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--; // 1 based indexing
        cout << (query(0, 0, s.length() - 1, l, r, seg).full) * 2 << endl;
    }

    return 0;
}