#include<bits/stdc++.h>
using namespace std;





int main()
{
    //FIFO

    queue<int> q;

    q.push(3);
    q.push(2);

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;




    return 0;
}