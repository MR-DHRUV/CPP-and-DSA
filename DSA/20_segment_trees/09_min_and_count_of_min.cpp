#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

class SegTree
{
    ll seg1[400001]; // this will store min element
    ll seg2[400001]; // this will store count of min element
    ll size;

    void build(ll idx, ll low, ll high, vector<ll> &nums)
    {
        if (low == high)
        {
            seg1[idx] = nums[low];
            seg2[idx] = 1; // we have only one element
            return;
        }

        ll m = (low + high) / 2;

        build(2 * idx + 1, low, m, nums);
        build(2 * idx + 2, m + 1, high, nums);

        int left = 2 * idx + 1, right = 2 * idx + 2;

        seg1[idx] = min(seg1[left], seg1[right]);
        if (seg1[left] == seg1[right])
            seg2[idx] = seg2[left] + seg2[right];
        else if (seg1[left] < seg1[right])
            seg2[idx] = seg2[left];
        else
            seg2[idx] = seg2[right];
    }

    void updateHelper(ll idx, ll low, ll high, ll &i, ll &val)
    {
        if (low == high)
        {
            // for updation with new element
            if (seg1[idx] != val)
            {
                seg2[idx] = 1;
            }

            seg1[idx] = val;
            return;
        }

        ll m = (low + high) / 2;

        if (i <= m)
            updateHelper(2 * idx + 1, low, m, i, val);
        else
            updateHelper(2 * idx + 2, m + 1, high, i, val);

        int left = 2 * idx + 1, right = 2 * idx + 2;
        seg1[idx] = min(seg1[left], seg1[right]);

        if (seg1[left] == seg1[right])
            seg2[idx] = seg2[left] + seg2[right];
        else if (seg1[left] < seg1[right])
            seg2[idx] = seg2[left];
        else
            seg2[idx] = seg2[right];
    }

    pair<ll, ll> query(ll idx, ll low, ll high, ll &l, ll &r)
    {
        if (r < low || l > high)
            return {1e9 + 7, 0};

        if (low >= l && high <= r)
            return {seg1[idx], seg2[idx]};

        ll m = (low + high) / 2;

        pair<ll, ll> left = query(2 * idx + 1, low, m, l, r);
        pair<ll, ll> right = query(2 * idx + 2, m + 1, high, l, r);

        pair<ll, ll> ans;
        ans.first = min(left.first, right.first);

        if (left.first == right.first)
            ans.second = left.second + right.second;
        else if (left.first < right.first)
            ans.second = left.second;
        else
            ans.second = right.second;

        return ans;
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

    pair<ll, ll> rangeMin(ll left, ll right)
    {
        return query(0, 0, size, left, right);
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SegTree st(arr);
    ll a, b, c;

    while (m--)
    {
        cin >> a >> b >> c;
        if (a == 1)
            st.update(b, c);
        else
        {
            pair<ll, ll> ans = st.rangeMin(b, c - 1);
            cout << ans.first << " " << ans.second << endl;
        }
    }

    return 0;
}