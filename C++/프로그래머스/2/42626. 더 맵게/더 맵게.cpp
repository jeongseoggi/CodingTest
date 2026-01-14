#include<bits/stdc++.h>

using namespace std;


int solution(vector<int> scoville, int K) 
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    bool isOverScovile = false;

    for (int i = 0; i < scoville.size(); ++i)
    {
        pq.push(scoville[i]);
    }

    while (!pq.empty())
    {
        if (pq.top() >= K)
        {
            isOverScovile = true;
            break;
        }


        int firsttarget = pq.top();
        pq.pop();


        if (!pq.empty())
        {
            int secondTarget = pq.top();
            pq.pop();

            int addScovile = firsttarget + (secondTarget * 2);

            pq.push(addScovile);

            answer++;
        }
    }


    if (!isOverScovile)
    {
        answer = -1;
    }

    return answer;
}


