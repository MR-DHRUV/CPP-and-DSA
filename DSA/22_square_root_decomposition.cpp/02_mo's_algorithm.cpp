#include <bits/stdc++.h>
using namespace std;

// In Mo's algorithm we sort the queries in a fashion to decrease the overall complexity of the algorithm

// This sorting of queries is called offline processing
// we sort the queries in increasing order of left/rootN to determine in which bloack they fall
// is L/rootN is  same then we fist choose one with greater R

// What difference does it make
// if we sort the queries in the above fashion the average movement per query is of rootN

// Total Complexity : sorting queries + change in left pointer  + total movement

int rootN = 0;

// this is a code for range sum queries 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n;
    rootN = sqrtl(n);
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> q;
    vector<vector<int>> queries;
    int l, r;

    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        queries.push_back({l, r, i});
    }

    // sorting queries
    // we sorting them is such a way that the movement b/w any two consicutive queries is rootN
    // this sorting function is called Mo's comparator
    sort(queries.begin(), queries.end(), [](vector<int> &a, vector<int> &b)
         {
        if(a[0]/rootN == b[0]/rootN)
            return a[1] > b[1];

        return a[0]/rootN < b[0]/rootN; });

    vector<int> ans(q);
    int curr_l = 0, curr_r = -1, curr_ans = 0;

    // using this stratage net complexity = Q*rootN + N*rootN
    // N*rootN is the total movement in the array
    // => (N+Q)*rootN
    for (int i = 0; i < q; i++)
    {
        l = queries[i][0] - 1, r = queries[i][1] - 1;

        // expansion
        while (curr_r < r)
        {
            curr_r++;
            curr_ans += arr[curr_r];
        }

        while (curr_l > l)
        {
            curr_l--;
            curr_ans += arr[curr_l];
        }

        // contraction
        while (curr_r > r)
        {
            curr_ans -= arr[curr_r];
            curr_r--;
        }

        while (curr_l < l)
        {
            curr_ans -= arr[curr_l];
            curr_l++;
        }

        ans[queries[i][2]] = curr_ans;
    }

    for (auto &i : ans)
        cout << i << endl;

    return 0;
}