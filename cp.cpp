#include <bits/stdc++.h>
using namespace std;

void build(int ind, int low, int high, int arr[], int seg[], int orr)
{
    if (low == high)
    {
        seg[ind] = arr[low];
        return;
    }

    int mid = (high + low) / 2;
    build((2 * ind) + 1, low, mid, arr, seg, !orr);
    build((2 * ind) + 2, mid + 1, high, arr, seg, !orr);

    if (orr) seg[ind] = seg[(2 * ind) + 1] | seg[(2 * ind) + 2];
    else seg[ind] = seg[(2 * ind) + 1] ^ seg[(2 * ind) + 2];
}

void update(int ind,int low, int high, int seg[], int orr, int i, int val)
{
    if(low == high)
    {
        seg[ind] = val;
        return;
    }

    int mid = (high + low) / 2;
    
    if(i <= mid) update((2*ind)+1,low,mid,seg,!orr,i,val);
    else update((2*ind)+2,mid+1,high,seg,!orr,i,val);

    if (orr) seg[ind] = seg[(2 * ind) + 1] | seg[(2 * ind) + 2];
    else seg[ind] = seg[(2 * ind) + 1] ^ seg[(2 * ind) + 2];
}

void solve()
{
    // dekho pahle segment tree banalo for initial data then update it and print root
    int n, m;
    cin >> n >> m;
    int ele = pow(2, n);
    int arr[ele];
    for (int i = 0; i < ele; i++)
    {
        cin >> arr[i];
    }

    int seg[4*ele];
    if(n%2 == 0) build(0,0,ele-1,arr,seg,0);
    else build(0,0,ele-1,arr,seg,1);

    while (m--)
    {
        int i, val;
        cin >> i >> val;
        i--; // 1 based indexing
        
        if(n%2 == 0) update(0,0,ele-1,seg,0,i,val);
        else update(0,0,ele-1,seg,1,i,val);

        cout << seg[0] << endl;
    }
}

signed main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

// #ifndef IO_FROM_FILE
//     freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt", "r", stdin);
//     freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt", "w", stdout);
// #endif

    solve();

    return 0;
}