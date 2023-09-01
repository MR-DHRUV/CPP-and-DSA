#include <bits/stdc++.h>
using namespace std;

struct Query
{
    int l, r, idx;
    Query() {}
    Query(int l, int r, int i)
    {
        this->l = l;
        this->r = r;
        this->idx = i;
    }
};

int rootN = 1;
int arr[30001], freq[1000001]{0};
Query queries[200001];

// this is a code for range sum queries
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n;
    rootN = sqrtl(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> q;
    int l, r;

    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        queries[i] = Query(l, r, i);
    }

    // sorting queries
    sort(queries, queries + q, [](Query &a, Query &b)
         {
        if(a.l/rootN == b.l/rootN)
            return a.r > b.r;

        return a.l < b.l; });

    vector<int> ans(q);
    int curr_l = 0, curr_r = -1, curr_ans = 0;

    // using this stratagy net complexity = Q*rootN + N*rootN
    for (int i = 0; i < q; i++)
    {
        // zero based indexing
        l = queries[i].l - 1, r = queries[i].r - 1;

        // expansion
        while (curr_r < r)
        {
            curr_r++;
            freq[arr[curr_r]]++;

            // we have found a distinct element
            if (freq[arr[curr_r]] == 1)
                curr_ans++;
        }

        while (curr_l > l)
        {
            curr_l--;
            freq[arr[curr_l]]++;

            // we have found a distinct element
            if (freq[arr[curr_l]] == 1)
                curr_ans++;
        }

        // contraction
        while (curr_r > r)
        {
            freq[arr[curr_r]]--;

            // we have removed last occurance of this element
            if (freq[arr[curr_r]] == 0)
                curr_ans--;

            curr_r--;
        }

        while (curr_l < l)
        {
            freq[arr[curr_l]]--;

            // we have removed last occurance of this element
            if (freq[arr[curr_l]] == 0)
                curr_ans--;

            curr_l++;
        }

        ans[queries[i].idx] = curr_ans;
    }

    for (auto &i : ans)
        cout << i << endl;

    return 0;
}