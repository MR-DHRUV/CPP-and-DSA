#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '\\' || x == '^' || x == '(' || x == ')')
    {
        return false;
    }
    return true;
}

int getPrecidence(char x, bool inStack)
{
    if ((x == '+' || x == '-') && inStack == true)
    {
        return 2;
    }

    else if ((x == '+' || x == '-') && inStack == false)
    {
        return 1;
    }

    else if ((x == '*' || x == '/') && inStack == true)
    {
        return 4;
    }

    else if ((x == '*' || x == '/') && inStack == false)
    {
        return 3;
    }

    else if ((x == '^') && inStack == false)
    {
        return 6;
    }

    else if ((x == '^') && inStack == true)
    {
        return 5;
    }

    else if ((x == '(') && inStack == true)
    {
        return 0;
    }

    else if ((x == '(') && inStack == false)
    {
        return 7;
    }

    else if ((x == ')') && inStack == false)
    {
        return 0;
    }

    return -1;
}

string topostfix(string exp)
{
    string postfix;
    stack<char> st;
    st.push('#');

    for (int i = 0; i < exp.length(); i++)
    {
        if (isOperand(exp[i]) && exp[i])
        {
            postfix.push_back(exp[i]);
        }

        else
        {
            if (getPrecidence(exp[i], false) > getPrecidence(st.top(), true))
            {
                st.push(exp[i]);
            }
            else if (getPrecidence(exp[i], false) == getPrecidence(st.top(), true))
            {
                st.pop();
            }
            else
            {
                while (getPrecidence(exp[i], false) < getPrecidence(st.top(), true))
                {
                    if (st.top() != '(' && st.top() != ')')
                    {
                        postfix.push_back(st.top());
                    }
                    st.pop();
                }

                st.push(exp[i]);
            }
        }
    }

    while (st.empty() == false && st.top() != '#')
    {
        if (st.top() != '(' && st.top() != ')')
        {
            postfix.push_back(st.top());
        }
        st.pop();
    }

    return postfix;
}

int main()
{
    cout << topostfix("((a+b)*c)-d^e^f") << endl;

    return 0;
}