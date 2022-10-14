#include<bits/stdc++.h>
using namespace std;

void reverseStr(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }

    s.clear();

    while(st.empty() == false)
    {
        s.push_back(st.top());
        st.pop();
    }

    vector<int>a;
}

int main()
{
    string s = "abcde";
    reverseStr(s);
    cout<<s<<endl;
    
    return 0;
}