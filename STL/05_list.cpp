#include<bits/stdc++.h>
using namespace std;





int main()
{
    list <int> l;

    l.push_back(1);
    l.push_front(2);

    for(int i: l)
    {
        cout<<i<<" ";
    }
    
    cout<<endl;
    
    // same pop, back , front , begin ......

    l.erase(l.begin());

    list<int>::iterator iter = l.begin();
    cout<<*iter++<<endl;

    // list cannot be printed directly using [] or at operator , it can be only printed using iterators



    return 0;
}