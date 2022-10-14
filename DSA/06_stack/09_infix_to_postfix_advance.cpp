//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    bool isOperand(char x)
    {
        if (x == '*' || x == '/' || x == '+' || x == '-' || x == '(' || x == ')' || x == '^')
        {
            return false;
        }

        return true;
    }

    int getPriority(char x)
    {
        if (x == '^')
        {
            return 4;
        }
        if (x == '*' || x == '/')
        {
            return 3;
        }
        if (x == '+' || x == '-')
        {
            return 2;
        }
        if(x == '(' || x == ')')
        {
            return 1;
        }

        return -1;
    }

public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        stack<char> st;
        string ans;
        st.push('#');

        for (int i = 0; i < s.length(); i++)
        {
            if (isOperand(s[i]))
            {
                ans.push_back(s[i]);
            }
            else
            {
                if (s[i] == '(')
                {
                    st.push(s[i]);
                }
                else if (s[i] == ')')
                {
                    while (st.top() != '(')
                    {
                        ans.push_back(st.top());
                        st.pop();
                    }

                    if(st.top() == '(')
                    {
                      st.pop();  
                    }
  
                }
                else if (getPriority(s[i]) > getPriority(st.top()))
                {
                    st.push(s[i]);
                }
                else
                {
                    while (getPriority(s[i]) <= getPriority(st.top()))
                    {
                        ans.push_back(st.top());
                        st.pop();
                    }
                    
                    st.push(s[i]);
                }
            }
        }

        while (st.empty() == false && st.top() != '#')
        {
            ans.push_back(st.top());
            
            st.pop();
        }

        return ans;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends