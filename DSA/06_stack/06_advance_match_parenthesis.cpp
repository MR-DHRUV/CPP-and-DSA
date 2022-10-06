#include <bits/stdc++.h>
using namespace std;

// parentheses matching;
// we need to check that opening "(" and closing ")" are aqual or not
// matlab yeh dekhna haii ki yeh check krna haii ki koi bracket missing h ya nahi

// Apppraoch
// string ko ek ek krke iterate karo
// agar opening bracket ho toh stack me usse daaldo
// agar closing bracket aaye toh ek opening remove krdo

// agar last me after iteration koi opening bach jaye that means missing haii
// ya agar beech me opening khatam ho jaye aur closing aajaye that means opening kam hain

bool matchParenthesis(string s)
{
    stack<char> st;
    stack<char> st1;
    stack<char> st2;

    int i = 0;

    while (s[i] != '\0')
    {
        // for parenthesis (
        if (s[i] == '(')
        {
            st.push('(');
        }
        if (s[i] == ')')
        {
            // if stack is empty in between
            if (st.empty())
            {
                return false;
            }

            st.pop();
        }

        // for curly braces {
        if (s[i] == '{')
        {
            st1.push('{');
        }

        if (s[i] == '}')
        {
            // if stack is empty in between
            if (st1.empty())
            {
                return false;
            }

            st1.pop();
        }

        // for square brackets [
        if (s[i] == '[')
        {
            st2.push('[');
        }

        if (s[i] == ']')
        {
            // if stack is empty in between
            if (st2.empty())
            {
                return false;
            }

            st2.pop();
        }

        i++;
    }

    // agar last me empty ho gaya toh koi bracket missing nahi , sab ok haii
    if (st.empty() && st1.empty() && st2.empty())
    {
        return true;
    }

    return false;
}


// approach2 : instead of making multiple stacks we chan check for the last opened bracked and that should close first;
bool matchParenthesisOnce(string s)
{
    stack<char> st;

    int i = 0;

    while (s[i] != '\0')
    {
        char sym = s[i];

        if (sym == '(' || sym == '{' || sym == '[')
        {
            st.push(sym);
        }

        if (sym == ')' || sym == '}' || sym == ']')
        {
            bool ok = false;

            // if stack is empty in between
            if (st.empty())
            {
                return false;
            }

            if (sym == ')' && st.top() == '(')
            {
                ok = true;
                st.pop();
            }

            if (sym == '}' && st.top() == '{')
            {
                ok = true;
                st.pop();
            }

            if (sym == ']' && st.top() == '[')
            {
                ok = true;
                st.pop();
            }

            if (ok == false)
            {
                return false;
            }
        }
        i++;
    }

    // agar last me empty ho gaya toh koi bracket missing nahi , sab ok haii
    if (st.empty())
    {
        return true;
    }

    return false;
}

int main()
{

    string s = "({[(a+b(]))[ * {(a-b)}]]})";

    cout << matchParenthesis(s) << endl;
    cout << matchParenthesisOnce(s) << endl;

    return 0;
}
