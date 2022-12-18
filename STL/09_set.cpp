#include <bits/stdc++.h>
using namespace std;

int main()
{

    // sorted , so u cant push and pop , u can only insert, position will be decided by set itself
    set<int> s;
    
    // complexity of insert is logN
    s.insert(3);
    s.insert(4);
    s.insert(6);
    s.insert(1);
    s.insert(8);
    s.insert(2);
    s.insert(0);

    for (auto i : s)
    {
        cout << i << endl;
    }
    cout << endl;

    s.erase(s.begin());

    for (auto i : s)
    {
        cout << i << endl;
    }
    cout << endl;

    // erase at a index

    set<int>::iterator it = s.begin();

    it++;
    it++;

    s.erase(it);

    for (auto i : s)
    {
        cout << i << endl;
    }
    cout << endl;


    //given element present h ya ni, yeh batata haii
    cout<<"count "<<s.count(5)<<endl;
    cout<<"count "<<s.count(8)<<endl;

    //returns an iterator pointer to index of given element
    set<int>::iterator itr = s.find(8);
    
    cout<<*itr<<endl;


    return 0;
}