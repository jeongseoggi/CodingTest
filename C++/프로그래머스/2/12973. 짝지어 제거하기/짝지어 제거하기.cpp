#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer = 0;

    stack<char> st;

    st.push(s[0]);

    int index = 1;

    while (true)
    {
        if (index >= s.size()) break;

        if (st.empty())
        {
            st.push(s[index]);
            index++;
            continue;
        }

        char tempC = st.top();

        if (s[index] == tempC)
        {
            st.pop();
        }
        else
        {
            st.push(s[index]);
        }

        index++;

    }

    if (st.empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}