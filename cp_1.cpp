#include <bits/stdc++.h>
#define mat vector<vector<int>>

using namespace std;

class SegTree
{
    mat *seg;
    int size;
    int mod;

    inline mat multiply(mat a, mat b)
    {
        mat res(2, vector<int>(2, 0));

        res[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod;
        res[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod;
        res[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod;
        res[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod;

        return res;
    }

    void build(int idx, int low, int high)
    {
        if (low == high)
        {
            seg[idx] = vector<vector<int>>(2, vector<int>(2, 0));
            cin >> seg[idx][0][0] >> seg[idx][0][1] >> seg[idx][1][0] >> seg[idx][1][1];
            return;
        }

        int m = (low + high) / 2;
        build(2 * idx + 1, low, m);
        build(2 * idx + 2, m + 1, high);

        // multiply matrices
        seg[idx] = multiply(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    // core optimizarion
    // do not do unneccassary multiplications
    mat queryHelper(int idx, int low, int high, int &l, int &r)
    {
        if (low >= l && high <= r)
            return seg[idx];

        int mid = (low + high) >> 1;
        bool a = true, b = true;
        mat left, right;

        // do not make unneccacary caints
        if (!(low > r || mid < l))
            left = queryHelper(2 * idx + 1, low, mid, l, r);
        else
            a = false;
        if (!(mid + 1 > r || high < l))
            right = queryHelper(2 * idx + 2, mid + 1, high, l, r);
        else
            b = false;

        if (!a)
            return right;
        else if (!b)
            return left;

        return multiply(left, right);
    }

public:
    SegTree(int n, int r)
    {
        seg = new mat[4 * n];
        mod = r;
        size = n - 1;
        build(0, 0, size);
    }

    mat query(int &l, int &r)
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

    int r, n, m;
    cin >> r >> n >> m;
    SegTree st(n, r);

    int a, b;
    while (m--)
    {
        cin >> a >> b;

        mat ans = st.query(--a, --b);

        cout << ans[0][0] << " ";
        cout << ans[0][1] << " ";
        cout << endl;
        cout << ans[1][0] << " ";
        cout << ans[1][1] << " ";
        cout << endl;

        cout << endl;
    }

    return 0;
}
