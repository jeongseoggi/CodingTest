#include <bits/stdc++.h>

using namespace std;

int solution(int n) 
{
    int answer = 1;

    vector<int> v;

    for (int i = 1; i <= n; ++i)
    {
        v.push_back(i);
    }

  

    int startIndex = 0;
    int endIndex = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        int value = accumulate(v.begin() + startIndex, v.begin() + endIndex, 0);

        if (value == n)
        {
            answer++;
            startIndex++;
            continue;
        }

        if (value > n)
        {
            startIndex++;
            continue;
        }

        if (value < n)
        {
            endIndex++;
            continue;
        }
    }

    return answer;
}