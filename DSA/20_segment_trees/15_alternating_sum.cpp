#include <bits/stdc++.h>
#define ll long long int
#define MAX 400010
#define p pair<ll, ll>
using namespace std;

class SegTree
{
    // In this questions we are building a segment tree with two variables for each node
    // we'll just sum prefix and suffix from lefft and right but with only 1 change
    // we'll initialize nodes of odd indices with val,0 and even indices with 0,val
    // WHY THIS WORKS 
    // prefix contains the sum of odd indices while the suffix contains the sum of even indices 
    // so its either odd-even or even-odd depending upon the start point of the range

    ll prefix[MAX]{0}, suffix[MAX]{0};
    ll size;

    void build(ll idx, ll low, ll high, vector<ll> &nums)
    {
        if (low == high)
        {
            // odd index
            if (low & 1)
            {
                prefix[idx] = nums[low];
                suffix[idx] = 0;
            }
            else
            {
                prefix[idx] = 0;
                suffix[idx] = nums[low];
            }

            return;
        }

        ll m = (low + high) / 2;
        build(2 * idx + 1, low, m, nums);
        build(2 * idx + 2, m + 1, high, nums);

        // prefix sum
        prefix[idx] = prefix[2 * idx + 1] + prefix[2 * idx + 2];

        // suffix sum
        suffix[idx] = suffix[2 * idx + 1] + suffix[2 * idx + 2];
    }

    void updateHelper(ll idx, ll low, ll high, ll &target, ll &val)
    {
        // current interval ka koi lena dena nahi haii
        if (target < low || target > high)
            return;

        if (low == high)
        {
            if (low & 1)
            {
                prefix[idx] = val;
                suffix[idx] = 0;
            }
            else
            {
                prefix[idx] = 0;
                suffix[idx] = val;
            }

            return;
        }

        ll mid = low + (high - low) / 2;

        updateHelper((2 * idx) + 1, low, mid, target, val);
        updateHelper((2 * idx) + 2, mid + 1, high, target, val);

        // prefix sum
        prefix[idx] = prefix[2 * idx + 1] + prefix[2 * idx + 2];

        // suffix sum
        suffix[idx] = suffix[2 * idx + 1] + suffix[2 * idx + 2];
    }

    p queryHelper(ll idx, ll low, ll high, ll &l, ll &r)
    {
        if (r < low || l > high)
            return {0, 0};

        if (low >= l && high <= r)
            return {prefix[idx], suffix[idx]};

        ll mid = (low + high) / 2;

        p left = queryHelper(2 * idx + 1, low, mid, l, r);
        p right = queryHelper(2 * idx + 2, mid + 1, high, l, r);

        return {left.first + right.first, left.second + right.second};
    }

public:
    SegTree(vector<ll> &nums)
    {
        size = nums.size() - 1;
        build(0, 0, size, nums);
    }

    void update(ll target, ll val)
    {
        updateHelper(0, 0, size, target, val);
    }

    p query(ll &l, ll &r)
    {
        return queryHelper(0, 0, size, l, r);
    }
};

int main()
{
// #ifndef IO_FROM_FILE
//     freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
//     freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
// #endif

    ll n, m;
    cin >> n;
    vector<ll> nums(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    SegTree st(nums);
    cin >> m;

    ll t, a, b;
    while (m--)
    {
        cin >> t >> a >> b;

        if (t == 0)
        {
            st.update(--a, b);
        }
        else
        {
            p ans = st.query(--a, --b);
            if (a & 1)
                cout << ans.first - ans.second << endl;
            else
                cout << ans.second - ans.first << endl;
        }
    }

    return 0;
}