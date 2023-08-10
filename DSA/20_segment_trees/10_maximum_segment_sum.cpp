#include <bits/stdc++.h>
#define ll long long int

using namespace std;

class Node
{
public:
    ll pref, suff, sum, ans;
    Node() : pref(0), suff(0), sum(0), ans(0){};
    Node(ll a, ll b, ll c, ll d) : pref(a), suff(b), sum(c), ans(d){};
};

class SegTree
{
    // for this problem we need a 4 variable segment tree
    // We need to store suffix, prefix, sum and ans for each node

    Node seg[400010];   
    ll size;

    void build(ll idx, ll low, ll high, vector<ll> &nums)
    {
        if (low == high)
        {
            if (nums[low] <= 0)
            {
                // if we encountered a negitive element
                // then maximum prefix will be zero and suffix will be zero
                // sum till that node will be its value
                // ans will be zero as maximum will be zero by excluding this element
                seg[idx] = Node(0, 0, nums[low], 0);
            }
            else
            {
                // single positive element
                // suffix = prefix = sum = ans
                seg[idx] = Node(nums[low], nums[low], nums[low], nums[low]);
            }
            return;
        }

        ll m = (low + high) / 2;

        build(2 * idx + 1, low, m, nums);
        build(2 * idx + 2, m + 1, high, nums);

        Node left = seg[2 * idx + 1], right = seg[2 * idx + 2];

        // true sum
        ll sum = left.sum + right.sum;

        // prefix wo maximum sum haii jo maii left subarray ke start se le skta hu
        // maximum prefix at this node will be
        // either prefix of left part or sum of left + prefix of right
        ll prefix = max(left.pref, left.sum + right.pref);

        // suffix wo maximum sum haii jo maii right subarray ke end se le skta hu
        ll suffix = max(left.suff + right.sum, right.suff);

        // ans will be either same as left/right ka ans or we can have a new ans by adding suffix of left part and prefix of left part
        // concider it as end se sum left wale ka + start se max sum right wale ka as we cannot have breaks in b/w our segment, its like a subarray
        ll ans = max(left.suff + right.pref, max(left.ans, right.ans));

        seg[idx] = Node(prefix, suffix, sum, ans);
    }

    void updateHelper(ll idx, ll low, ll high, ll &i, ll &val)
    {
        if (low == high)
        {
            if (val <= 0)
            {
                seg[idx] = Node(0, 0, val, 0);
            }
            else
            {
                seg[idx] = Node(val, val, val, val);
            }

            return;
        }

        ll m = (low + high) / 2;

        if (i <= m)
            updateHelper(2 * idx + 1, low, m, i, val);
        else
            updateHelper(2 * idx + 2, m + 1, high, i, val);

        Node left = seg[2 * idx + 1], right = seg[2 * idx + 2];

        ll sum = left.sum + right.sum;
        ll prefix = max(left.pref, left.sum + right.pref);
        ll suffix = max(left.suff + right.sum, right.suff);
        ll ans = max(left.suff + right.pref, max(left.ans, right.ans));

        seg[idx] = Node(prefix, suffix, sum, ans);
    }

public:
    SegTree(vector<ll> &nums)
    {
        size = nums.size() - 1;
        build(0, 0, nums.size() - 1, nums);
    }

    void update(ll index, ll val)
    {
        updateHelper(0, 0, size, index, val);
    }

    ll query() { return seg[0].ans; }
};

signed main()
{
// #ifndef IO_FROM_FILE
//     freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
//     freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
// #endif

    ll n, m;
    cin >> n >> m;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SegTree st(arr);
    ll a, b;

    cout << st.query() << endl;

    while (m--)
    {
        cin >> a >> b;
        st.update(a, b);
        cout << st.query() << endl;
    }

    return 0;
}