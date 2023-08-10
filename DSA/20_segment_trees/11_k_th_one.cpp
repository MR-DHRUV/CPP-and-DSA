#include <bits/stdc++.h>
#define ll long long int
#define MAX_N 400010
using namespace std;

class SegTree
{
    // this is a question of desending the segment tree pattern
    ll seg[MAX_N];
    ll size;

    void build(ll idx, ll low, ll high, vector<ll> &nums)
    {
        if (low == high)
        {
            seg[idx] = nums[low];
            return;
        }

        ll m = (low + high) / 2;

        build(2 * idx + 1, low, m, nums);
        build(2 * idx + 2, m + 1, high, nums);

        int left = seg[2 * idx + 1], right = seg[2 * idx + 2];

        // simple sum ka seg tree bana dia haii humne
        seg[idx] = left + right;
    }

    void updateHelper(ll idx, ll low, ll high, ll &i)
    {
        if (low == high)
        {
            seg[idx] = !seg[idx]; // invert value
            return;
        }

        ll m = (low + high) / 2;

        if (i <= m)
            updateHelper(2 * idx + 1, low, m, i);
        else
            updateHelper(2 * idx + 2, m + 1, high, i);

        int left = seg[2 * idx + 1], right = seg[2 * idx + 2];
        seg[idx] = left + right;
    }

    // here is how we will find index of k'th one from a sum  segement tree
    // we will descend or go down in a segment tree until we find the k'th one
    int queryHelper(ll idx, ll low, ll high, int k)
    {
        // we have our, k'th one retun the index
        if (low == high)
            return low;

        int mid = (low + high) / 2;

        // now we need to see ki k'th 1 kaha padega left me ya right me
        // by analysing the sum
        // if sum of 1's on the left is less than k that means k'th one will be in the right part
        // basically we are navigating to the 1 that makes the sum as k starting from 0'th index
        if (k <= seg[2 * idx + 1])
            return queryHelper(2 * idx + 1, low, mid, k);
        else
            return queryHelper(2 * idx + 2, mid + 1, high, k - seg[2 * idx + 1]);
        // ab yaha pr k me se left child ka sum hata dia as right child me apne sum honge starting from 0 and we have skipped one's equal to sum in left child
    }

public:
    SegTree(vector<ll> &nums)
    {
        size = nums.size() - 1;
        build(0, 0, nums.size() - 1, nums);
    }

    void update(ll index)
    {
        updateHelper(0, 0, size, index);
    }

    ll query(int k)
    {
        // now humne k+1 isilie kia kyuki 1'st 1 jo 0 par hoga uska sum 1 hoga toh we are querying by sum
        return queryHelper(0, 0, size, k + 1);
    }
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

    while (m--)
    {
        cin >> a >> b;

        if (a == 1)
            st.update(b);
        else
            cout << st.query(b) << endl;
    }

    return 0;
}