#include <bits/stdc++.h>
using namespace std;

int main()
{

    // if we have more pegion than holes then atleast one hole will have more than one pegion

    // Problem Divisible subset: codechef
    // find a subset such that sum of the subset's elements is divisible by N where N is the size of set

    // For this question we will prove that our ans will be a subarray using pegion hole principle

    // To find subarray sum we can prefix the array
    // Sum of any subarray = (b-a)
    // To check if its divisible or not we can say
    // (b-a)%n = 0
    // b%n = a%n

    // so %n will yeild values from 0 to n-1
    // if any subarray sum %n has a value 0, then we are already done else
    // we have only values from 1 to n-1, thus there will exist a bucket with more than 1 value which is our ans

    cin.tie(NULL);
    ios_base::sync_with_stdio(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        unordered_map<int, vector<int>> mp;
        cin >> arr[0];

        arr[0] %= n;
        mp[arr[0]].push_back(0);

        for (int i = 1; i < n; i++)
        {
            cin >> arr[i];
            arr[i] = (arr[i] + arr[i - 1]) % n;
            mp[arr[i]].push_back(i);
        }

        int s = -1, e = -1;

        for (auto &it : mp)
        {
            if (it.first == 0)
            {
                s = 0, e = it.second[0];
                break;
            }
            else if (it.second.size() > 1)
            {
                s = it.second[0] + 1, e = it.second[1];
                break;
            }
        }

        if (s == -1)
            cout << -1 << endl;
        else
        {
            cout << (e - s + 1) << endl;
            for (int i = s; i <= e; i++)
            {
                cout << i + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}