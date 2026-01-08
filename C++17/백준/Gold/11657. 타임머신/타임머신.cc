#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int from;
    int to;
    int cost;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<Edge> edges;

    for(int i = 0; i < M; ++i)
    {
        int from, to, cost;

        cin >> from >> to >> cost;

        edges.push_back({from, to, cost});
    }

    vector<long long> dist(N + 1, INT_MAX);
    dist[1] = 0;

    bool HasLoop = false;

    for(int i = 1; i <= N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            int cur = edges[j].from;
            int next = edges[j].to;
            int cost = edges[j].cost;

            if(dist[cur] == INT_MAX)
            {
                continue;
            }

            if (dist[next] > dist[cur] + cost) 
            {
                dist[next] = dist[cur] + cost;

                // N번째 라운드에서도 값이 갱신된다면 음수 사이클 존재
                if (i == N) {
                    HasLoop = true;
                }
            }
        }
    }
    

    if(HasLoop)
    {
        cout << "-1" << "\n";
    }
    else
    {
        for(int i = 2; i < dist.size(); ++i)
        {
           if (dist[i] == INT_MAX) 
            {
                cout << -1 << "\n"; // 도달할 수 없는 경우
            } 
            else 
            {
                cout << dist[i] << "\n";
            }
        }

    }

    return 0;
}