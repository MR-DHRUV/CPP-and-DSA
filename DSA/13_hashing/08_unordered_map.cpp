#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> mp;

    // insertion
    pair<string, int> p = make_pair("DSA", 1);
    mp.insert(p);

    // insertion
    mp["mera"] = 2;

    // Inportant
    // cout<<mp.at("unknown-key")<<endl; // this is throw an arror as the key is not present

    // this will simply print 0 as it creates an entry for unknown key ans initilisez it with base value
    cout << mp["unknown-key"] << endl;

    // now this will also return 0 as there exists an entry
    cout << mp.at("unknown-key") << endl;

    // Size
    int size = mp.size();
    cout << size << endl;

    // to check presence of a key we use count
    cout << mp.count("kya tum ho?") << endl;

    // erase an entry
    mp.erase("mera");

    // mp.find return an iterator
    // when a key is not present iter will point to end of list i.e mp.end()
    auto iter = mp.find("kya tum ho?");

    // order is not maintained in unordered_map while map maintains the order in which data is added
    



    return 0;
}