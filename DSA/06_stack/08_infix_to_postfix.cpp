#include <bits/stdc++.h>
using namespace std;

// will return the precedence of the given operator
int getPrecedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '\\')
    {
        return 2;
    }

    return 0;
}

// will hceck given character is operator or symbol
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '\\')
    {
        return 0;
    }

    return 1;
}

string toPostfix(string s)
{
    string postfix;
    stack<char> st;
    st.push('#');

    for (int i = 0; i < s.length(); i++)
    {
        if (isOperand(s[i]))
        {
            postfix.push_back(s[i]);
        }
        else
        {
            if (getPrecedence(s[i]) > getPrecedence(st.top()))
            {
                st.push(s[i]);
            }
            else
            {
                while (getPrecedence(s[i]) <= getPrecedence(st.top()))
                {
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    while (st.empty() == false)
    {
        postfix.push_back(st.top());
        st.pop();
    }

    postfix.pop_back();

    return postfix;
}

int main()
{
    string ans = toPostfix("a+b*c/d");
    cout << ans << endl;

    return 0;
}