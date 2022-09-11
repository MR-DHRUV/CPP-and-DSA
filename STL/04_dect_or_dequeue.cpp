#include<bits/stdc++.h>
using namespace std;





int main()
{
    // doubbly ended queue

    // non contigoues memory locations par store hota haii data
    // dynamic, thus size can be increased

    deque<int> d;

    // adding elements
    d.push_back(1);
    d.push_front(2);

    // for i=0 to d tak haii
    for ( int i: d)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    // deleting elements

    // d.pop_front();
    // d.pop_back();

    //accessing elements
    cout<<d.at(0)<<endl;

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    cout<<d.empty()<<endl;

    //iterators
    //.begin , .end

    //erase
    cout<<d.size()<<endl;
    
    //removes 1st element
    d.erase(d.begin(), d.begin()+1);
    cout<<d.size()<<endl;

    // cout<<d.at(0)<<endl;

    



    

    return 0;
}