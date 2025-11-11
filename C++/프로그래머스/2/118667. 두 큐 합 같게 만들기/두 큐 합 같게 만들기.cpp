#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) 
{
    int answer = 0;

    queue<int> q1;
    queue<int> q2;
    long sumQueue1 = 0;
    long sumQueue2 = 0;

    for (int i = 0; i < queue1.size(); ++i)
    {
        q1.push(queue1[i]);
        sumQueue1 += queue1[i];
    }

    for (int i = 0; i < queue2.size(); ++i)
    {
        q2.push(queue2[i]);
        sumQueue2 += queue2[i];
    }

    if ((sumQueue1 + sumQueue2) % 2 != 0)
    {
        return -1;
    }

    while (!(q1.size() < 1 || q2.size() < 1))
    {
        if (answer / 2 > q1.size() + q2.size())
        {
            return -1;
        }

        if (sumQueue1 > sumQueue2)
        {
            sumQueue1 -= q1.front();
            sumQueue2 += q1.front();
            q2.push(q1.front());
            q1.pop();
            answer++;
        }
        else if (sumQueue2 > sumQueue1)
        {
            sumQueue2 -= q2.front();
            sumQueue1 += q2.front();
            q1.push(q2.front());
            q2.pop();
            answer++;
        }
        else if (sumQueue1 == sumQueue2)
        {
            return answer;
        }
    }

    if (sumQueue1 == sumQueue2)
    {
        return answer;
    }
    return -1;
}