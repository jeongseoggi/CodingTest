#include <bits/stdc++.h>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) 
{
    int answer = 0;
    vector<vector<pair<int, int>>> graph(N + 1);
    vector<int> distance(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (const auto& r : road)
    {
        graph[r[0]].emplace_back(r[1], r[2]);
        graph[r[1]].emplace_back(r[0], r[2]);
    }

    distance[1] = 0; // 시작점 0으로 초기화 -> 1번 마을
    pq.emplace(0, 1); // 1번 마을 시작 비용(0)

    while (!pq.empty())
    {
        int dist = pq.top().first; // 현재 비용
        int now = pq.top().second; // 현재 위치

        pq.pop();

        if (dist > distance[now])
        {
            continue;
        }

        for (const auto& next : graph[now])
        {
            int cost = dist + next.second;

            if (cost < distance[next.first])
            {
                distance[next.first] = cost;
                pq.emplace(cost, next.first);
            }
        }
    }

    for (int i = 0; i < distance.size(); ++i)
    {
        if (distance[i] <= K)
        {
            answer++;
        }
    }


    return answer;
}