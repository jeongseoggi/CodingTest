#include <bits/stdc++.h>

using namespace std;

int WordChange(string begin, const string& target, stack<string>& q, int count, int index)
{
    if (begin == target)
    {
        return count;
    }
    int diffCnt = 0;
    for (int i = 0; i < begin.size(); ++i)
    {
        if (begin[i] != target[i])
        {
            diffCnt++;
        }
    }
    if (diffCnt < 2)
    {
        return count + 1;
    }
    else
    {
        stack<string> temp;

        while (true)
        {
            int diffCount = 0;
            string popStr = q.top();
            q.pop();

            for (int i = 0; i < begin.size(); ++i)
            {
                if (begin[i] != popStr[i])
                {
                    diffCount++;
                }
            }
            if (diffCount < 2)
            {
                begin = popStr;
                break;
            }
            else
            {
                temp.push(popStr);
            }

        }

        if (temp.size() > 0)
        {
            q = temp;
        }
    }

   
    return WordChange(begin, target, q, count + 1, index + 1);
}

int solution(string begin, string target, vector<string> words) 
{
    int answer = 0;

    stack<string> st;

    if (find(words.begin(), words.end(), target) == words.end())
    {
        return 0;
    }

    for (const string& str : words)
    {
        st.push(str);
    }


    return WordChange(begin, target, st, 0, 0);
}