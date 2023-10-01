#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long int

bool solve(vector<int> &v)
{
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    int val = ((v[i] ^ v[j]) ^ (v[k] ^ v[l]));
                    if (val == 0)
                        return true;
                }
            }
        }
    }
    return false;
}

int32_t main()
{
    // we have to find 4 numbers which xor to 4
    // and we are given that 2 consicutive numbers only differ by 1 bit
    // so if we zor them we get all zeros except 1 at one position
    // so our task is to find 2 non overlaping pairs which yeils 1 at same position

    // Now using pegion hole principle, if we have >= 130 numbers, our ans will be always yes as
    // every 2 numbers will set a single bit
    // total 64 bit
    // there must exist 2 pairs that set the same bit

    int n;
    cin >> n;

    if (n >= 130)
    {
        cout << "Yes" << endl;
    }
    else
    {
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (solve(arr))
            cout << "Yes" << endl;

        else
            cout << "No" << endl;
    }

    return 0;
}
