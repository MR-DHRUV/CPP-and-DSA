#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define int long long
const int LIMIT = 10000;

// Function to calculate Grundy numbers up to a given limit
void calculate_grundy(vector<int> &grundy, int limit)
{
    grundy[0] = 0;
    for (int i = 1; i <= limit; ++i)
    {
        unordered_set<int> reachable;
        reachable.insert(grundy[i - 1]);
        for (int j = 1; j <= i / 2; ++j)
        {
            reachable.insert(grundy[j] ^ grundy[i - j]);
        }
        int g = 0;
        while (reachable.count(g))
        {
            ++g;
        }
        grundy[i] = g;
    }
}

string solve_game(int n, const vector<int> &piles, const vector<int> &grundy)
{
    int nim_sum = 0;
    for (int pile : piles)
    {
        if (pile < grundy.size())
        {
            nim_sum ^= grundy[pile];
        }
        else
        {
            nim_sum ^= grundy[pile % (LIMIT + 1)];
        }
    }
    return nim_sum != 0 ? "Jean" : "Kaeya";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<int> grundy(LIMIT + 1);
    calculate_grundy(grundy, LIMIT);

    vector<string> results;
    for (int t = 0; t < T; ++t)
    {
        int n;
        cin >> n;
        vector<int> piles(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> piles[i];
        }
        results.push_back(solve_game(n, piles, grundy));
    }

    for (const string &result : results)
    {
        cout << result << '\n';
    }

    return 0;
}
