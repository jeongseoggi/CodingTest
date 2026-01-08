#include <bits/stdc++.h>

using namespace std;
const long long INF = 1e18; 

struct Edge
{
    int from;
    int to;
    int cost;
};


int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // 문제에서 주어진 대로 방향성 있는 간선 추가
        edges.push_back({a, b, c});
    }

    // 거리 테이블 초기화
    vector<long long> dist(N + 1, INF);
    dist[1] = 0; // 1번 도시에서 출발

    // 벨만-포드 알고리즘 수행
    // N-1번의 반복 + 1번의 사이클 확인 = 총 N번 반복
    bool hasNegativeCycle = false;

    for (int i = 1; i <= N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            int cur = edges[j].from;
            int next = edges[j].to;
            int cost = edges[j].cost;

            // 현재 간선의 출발지가 방문 불가능한 곳(INF)이면 패스
            if (dist[cur] == INF) continue;

            // 최단 거리 갱신 로직 (Relaxation)
            if (dist[next] > dist[cur] + cost) 
            {
                dist[next] = dist[cur] + cost;

                // N번째 라운드에서도 값이 갱신된다면 음수 사이클 존재
                if (i == N)
                {
                    hasNegativeCycle = true;
                }
            }
        }
    }

    if (hasNegativeCycle) 
    {
        cout << -1 << "\n";
    } 
    else 
    {
        // 2번 도시부터 N번 도시까지의 최단 거리 출력
        for (int i = 2; i <= N; i++) 
        {
            if (dist[i] == INF) 
            {
                cout << -1 << "\n"; // 도달할 수 없는 경우
            } 
            else 
            {
                cout << dist[i] << "\n";
            }
        }
    }
}