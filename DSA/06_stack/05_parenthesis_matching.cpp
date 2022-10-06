#include<bits/stdc++.h>
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

    int i = 0;

    while(s[i] != '\0')
    {
        if(s[i] == '(')
        {
            st.push('(');
        }
        if(s[i] == ')')
        {
            // if stack is empty in between
            if(st.empty())
            {
                return false;
            }

            st.pop();
        }
        i++;
    }

    // agar last me empty ho gaya toh koi bracket missing nahi , sab ok haii
    if(st.empty())
    {
        return true;
    }
    
    return false;
}


int main()
{
     
    string s = "(((a+b) * (a-b)";

    cout<<matchParenthesis(s)<<endl;

    return 0;
}