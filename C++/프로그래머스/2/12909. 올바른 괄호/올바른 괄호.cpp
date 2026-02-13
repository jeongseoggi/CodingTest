#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    if (s[0] == ')' || s[s.size() - 1] == '(')
    {
        return false;
    }

    stack<char> st;

    st.push(s[0]);

    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
            continue;
        }
        else if (s[i] == ')' && st.size() != 0)
        {
            st.pop();
        }
        else if (st.size() == 0 && s[i] == ')')
        {
            return false;
        }
    }

    if (st.size() != 0)
    {
        return false;
    }


    return true;
}