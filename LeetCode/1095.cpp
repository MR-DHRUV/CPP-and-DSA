#include <bits/stdc++.h>
using namespace std;

int sqrtN(long long int N)
{
    // Write your code here.
    int s = 0;
    int e = N/2;

    int ans = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        long long int square = abs(mid * mid);
        cout << mid << endl;
        // cout << square << endl;

        if (square == N)
        {
            return mid;
        };

        if (square < N)
        {
            ans = mid;
            s = mid+1;
        }
        else if(square > N)
        {
            e = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> a = {0, 1, 0, 1, 1, 2, 2, 3, 3, 4};

    cout << sqrtN(777777);

    return 0;
}