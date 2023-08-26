#include <bits/stdc++.h>
#define ll long long int
#define MAX_BIT 64
using namespace std;

class Node
{
public:
    ll sum;

    // it will store the count of any set bit present in numbers that have occured in sum of this node
    ll bits[MAX_BIT]{0};
    Node(){};
    Node(int n)
    {
        sum = n;

        // compute its bit values
        for (int i = 0; i < MAX_BIT; i++)
        {
            ll mask = 1ll << i;
            if (mask & n)
                bits[i] = 1;
        }
    }

    Node(Node &a, Node &b)
    {
        sum = a.sum + b.sum;

        for (int i = 0; i < MAX_BIT; i++)
        {
            bits[i] = a.bits[i] + b.bits[i];
        }
    }
};

class SegTree
{
    // in order to accomodate xor we can do the folowing
    // a -> 1010
    // b -> 1100
    // a+b -> 22

    // now to apply xor operation to a node that stores a+b be can do the following
    // say I want to xor by c = 1101
    // a^c = 0111
    // b^c = 0001

    // we can see janhan pr xor me 1 haii waha bit toggle ho jata haii and jaha 0 haii waha same rehta haii
    // toh we dont have to worry about 0 bits in xor
    // now jab toggle hoga toh kisi ith bit ka contribution ya toh hatega ya toh add hoga
    // hume yehi compute krna haii by storing the bit data so that we can compute the changes at any bit index

    vector<Node> seg;
    vector<ll> lazy;
    ll size;

    void build(ll idx, ll low, ll high, vector<ll> &nums)
    {
        if (low == high)
        {
            seg[idx] = Node(nums[low]);
            return;
        }

        ll m = (low + high) / 2;

        build(2 * idx + 1, low, m, nums);
        build(2 * idx + 2, m + 1, high, nums);
        seg[idx] = Node(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void propagateDown(ll &idx, ll &low, ll &high)
    {
        if (lazy[idx] == 0)
            return;

        if (low == high)
        {
            seg[idx] = Node(seg[idx].sum ^ lazy[idx]);
            lazy[idx] = 0;
            return;
        }

        // compute affect of xor on current node
        ll sum = seg[idx].sum;

        ll x = lazy[idx];
        lazy[idx] = 0;

        lazy[2 * idx + 1] ^= x;
        lazy[2 * idx + 2] ^= x;

        for (int i = 0; i < MAX_BIT; i++)
        {
            ll mask = 1ll << i;

            // if bit is 1 in xor
            if (mask & x)
            {
                ll cnt1 = seg[idx].bits[i];
                // count of zeros is total elements in range - no of 1's
                ll cnt0 = (high - low + 1) - cnt1;

                ll diff = (cnt0 - cnt1);
                // change = diff * 2 raised to the power i
                sum += (diff * mask);

                // count of new 1's
                seg[idx].bits[i] = cnt0;
            }
        }

        seg[idx].sum = sum;
    }

    void update(ll idx, ll low, ll high, ll &l, ll &r, ll &val)
    {
        propagateDown(idx, low, high);

        if (r < low || l > high)
            return;

        if (low >= l && high <= r)
        {
            lazy[idx] ^= val;
            propagateDown(idx, low, high);
            return;
        }

        ll m = (low + high) / 2;

        update(2 * idx + 1, low, m, l, r, val);
        update(2 * idx + 2, m + 1, high, l, r, val);
        seg[idx] = Node(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    ll query(ll idx, ll low, ll high, ll &l, ll &r)
    {
        propagateDown(idx, low, high);

        if (r < low || l > high)
            return 0;

        if (low >= l && high <= r)
            return seg[idx].sum;

        ll m = (low + high) / 2;

        ll left = query(2 * idx + 1, low, m, l, r);
        ll right = query(2 * idx + 2, m + 1, high, l, r);

        return left + right;
    }

public:
    SegTree(vector<ll> &nums)
    {
        seg.resize(nums.size() * 4);
        lazy.resize(nums.size() * 4, 0);
        size = nums.size() - 1;
        build(0, 0, nums.size() - 1, nums);
    }

    void updateRange(ll l, ll r, ll val)
    {
        update(0, 0, size, l, r, val);
    }

    ll rangeSum(ll left, ll right)
    {
        return query(0, 0, size, left, right);
    }
};

int main()
{
    // #ifndef IO_FROM_FILE
    //     freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
    //     freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q, t, l, r, v;
    cin >> n;

    vector<ll> arr(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SegTree st(arr);

    cin >> q;
    while (q--)
    {
        cin >> t >> l >> r;
        --l;
        --r;

        if (t == 1)
        {
            cout << st.rangeSum(l, r) << endl;
        }
        else
        {
            cin >> v;
            st.updateRange(l, r, v);
        }
    }

    return 0;
}