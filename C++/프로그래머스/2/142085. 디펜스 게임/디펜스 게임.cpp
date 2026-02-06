#include <bits/stdc++.h>

using namespace std;

long long solution(int n, int k, vector<int> enemy)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < enemy.size(); i++)
    {
        pq.push(enemy[i]);

        if (pq.size() > k)
        {
            n -= pq.top();
            pq.pop();

            if (n < 0)
            {
                return i;
            }
        }
    }

    return enemy.size();
}

