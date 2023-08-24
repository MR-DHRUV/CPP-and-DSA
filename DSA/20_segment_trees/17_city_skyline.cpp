#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
class SegTree
{
    ll *seg;
    ll size;

    void updateHelper(ll idx, ll low, ll high, ll &i, ll &val)
    {
        if (low == high)
        {
            seg[idx] = max(seg[idx], val);
            return;
        }

        ll m = low + (high - low) / 2;

        if (i <= m)
            updateHelper(2 * idx + 1, low, m, i, val);
        else
            updateHelper(2 * idx + 2, m + 1, high, i, val);

        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    ll queryHelper(ll idx, ll low, ll high, ll &l, ll &r)
    {
        if (r < low || l > high)
            return 0;

        if (low >= l && high <= r)
            return seg[idx];

        ll m = low + (high - low) / 2;

        ll left = queryHelper(2 * idx + 1, low, m, l, r);
        ll right = queryHelper(2 * idx + 2, m + 1, high, l, r);

        return max(left, right);
    }

public:
    SegTree(int n)
    {
        size = n-1;
        seg = new ll[4 * n]{0};
    }

    void update(ll i, ll val)
    {
        updateHelper(0, 0, size, i, val);
    }

    ll query(ll left, ll right)
    {
        return queryHelper(0, 0, size, left, right);
    }
};

class Solution
{
public:
    vector<vector<ll>> getSkyline(vector<vector<ll>> &buildings)
    {
        // bas max ka segment tree bna do with point updates
        // hume range se koi mtlb nahi haii, we only need to concider start and end points


        vector<pair<int, int>> endpoints;
        for (const auto &building : buildings)
        {
            // Negative height for left endpoint
            endpoints.emplace_back(building[0], -building[2]); 
            
            // Positive height for right endpoint
            endpoints.emplace_back(building[1], building[2]);  
        }

        // sorting points on basis of x co-ordinate
        sort(endpoints.begin(), endpoints.end());

        SegTree st(endpoints.size());
        vector<vector<int>> ans;
        int prevMax = 0;

        for(auto &p : endpoints)
        {
            int &x = p.first, &h = p.second;
            
            // end point
            if(h < 0)
            {

            }
            // start point
            else
            {
                // st.update()
            }
        }


    }
};

ll main()
{

    return 0;
}