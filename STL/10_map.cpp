#include <bits/stdc++.h>
using namespace std;

int main()
{
    // collection of key value pairs
    // no duplicate keys
    // sorted
    map<int, string> m;

    // unordered map are unsorted

    m[1] = "babbar";
    m[13] = "dhruv";
    m[2] = "love";

    m.insert({5, "bheem"});

    for (auto i : m)
    {
        // first returns the key while second returns the value
        cout << i.first << " " << i.second << endl;
    }

    //complexity : logN
    cout << m.count(13) << endl;

    m.erase(m.begin());

    for (auto i : m)
    {
        // first returns the key while second returns the value
        cout << i.first << " " << i.second << endl;
    }


    auto it = m.find(5);

    cout<<(*it).first<<endl;
    cout<<(*it).second<<endl;

    return 0;
}