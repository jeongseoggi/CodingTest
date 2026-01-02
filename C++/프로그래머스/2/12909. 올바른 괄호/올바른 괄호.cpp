#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    if (s[0] == ')' || s[s.size() - 1] == '(')
    {
        return false;
    }

    queue<char> q;
    q.push(s[0]);

    for (int i = 1; i < s.size(); ++i)
    {
        if (q.empty())
        {
            q.push(s[i]);
            continue;
        }

        string temp = "";
        temp += q.front();
        temp += s[i];

        if (temp == "()")
        {
            q.pop();
        }
        else
        {
            q.push(s[i]);
        }
    }

    if (!q.empty())
    {
        answer = false;
    }


    return answer;
}
