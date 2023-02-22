#include<bits/stdc++.h>
using namespace std;


int getValue(int x , int y , char b)
{
    if(b == '*')
    {
        return x*y;
    }

    else if(b == '/')
    {
        return x/y;
    }

    else if(b == '+')
    {
        return x+y;
    }

    else if(b == '-')
    {
        return x-y;
    }

    return -1;
} 

bool isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
    {
        return false;
    }
    return true;
}

int evalPostfix(string exp)
{
    stack<int> st;

    for (int i = 0; i < exp.length(); i++)
    {
        if(isOperand(exp[i]))
        {
            st.push(exp[i] - '0');
        }

        else
        {
            if(st.size() < 2)
            {
                return -1;
            }

            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            // cout<<y<<" "<<exp[i]<<" "<<x<<endl;
            
            int ans = getValue(y,x,exp[i]);
            // cout<<ans<<endl;

            // very important
            st.push(ans);
        }

    }

    return st.top();
    
}

int main()
{
    cout<<evalPostfix("35*62/+4-")<<endl;
    
    return 0;
}