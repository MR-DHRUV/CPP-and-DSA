#include <bits/stdc++.h>
using namespace std;

struct Matrix
{
    int m[2][2];

    void read()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                scanf("%d", &m[i][j]);
            }
        }
    }

    void write()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (j)
                    printf(" ");
                printf("%d", m[i][j]);
            }
            puts("");
        }
        puts("");
    }
};

class SegTree
{
    vector<Matrix> seg;
    int size;
    int mod;

    inline void multiply(Matrix &a, Matrix &b, Matrix &res)
    {
        res.m[0][0] = (1ll * a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0]) % mod;
        res.m[0][1] = (1ll * a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1]) % mod;
        res.m[1][0] = (1ll * a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0]) % mod;
        res.m[1][1] = (1ll * a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1]) % mod;
    }

    void build(int idx, int low, int high)
    {
        if (low == high)
        {
            seg[idx].read();
        }
        else
        {
            int m = (low + high) >> 1;
            build(2 * idx + 1, low, m);
            build(2 * idx + 2, m + 1, high);

            // multiply matrices
            multiply(seg[2 * idx + 1], seg[2 * idx + 2], seg[idx]);
        }
    }

    // core optimizarion
    // do not do unneccassary multiplications
    void queryHelper(int idx, int low, int high, int &l, int &r, Matrix &m)
    {
        if (low >= l && high <= r)
        {
            m = seg[idx];
        }
        else
        {
            int mid = (low + high) >> 1;
            bool a = true, b = true;
            Matrix left, right;

            // do not make unneccacary calls
            if (!(low > r || mid < l))
                queryHelper(2 * idx + 1, low, mid, l, r, left);
            else
                a = false;
            if (!(mid + 1 > r || high < l))
                queryHelper(2 * idx + 2, mid + 1, high, l, r, right);
            else
                b = false;

            if (!a)
                m = right;
            else if (!b)
                m = left;
            else
                multiply(left, right, m);
        }
    }

public:
    SegTree(int n, int r)
    {
        seg.resize(4 * n);
        mod = r;
        size = n - 1;
        build(0, 0, size);
    }

    void query(int &l, int &r, Matrix &ans)
    {
        queryHelper(0, 0, size, l, r, ans);
    }
};

int main()
{
    // increases speed by prventing the overhead
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, n, m;
    scanf("%d%d%d", &r, &n, &m);
    SegTree st(n, r);

    int a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);

        Matrix ans;
        st.query(--a, --b, ans);
        ans.write();
    }

    return 0;
}
