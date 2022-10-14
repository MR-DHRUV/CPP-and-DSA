#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        // operator aur opening brackets ko stack me daaldo
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            bool popped = false;
            // agar 1 closing bracket aajaye toh jb tk ek opening bracket na aajaye saare operator hata do aur woh opening bracket bhi
            while (st.top() != '(' || st.empty() == true)
            {
                st.pop();
                popped = true;
            }

            if (st.top() == '(' && popped == true)
            {
                st.pop();
            }
        }
    }

    // last me agar opening bracket bach jaye toh matlab haii ki extra brackets the , agar operators bacche toh koi dikkat ni haii , all ok
    while (st.empty() == false)
    {
        if (st.top() == '(')
        {
            return true;
        }
        st.pop();
    }

    return false;
}

int main()
{

    return 0;
}