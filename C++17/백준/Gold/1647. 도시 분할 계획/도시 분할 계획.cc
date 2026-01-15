/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1647                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: hv4564 <boj.kr/u/hv4564>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1647                           #+#        #+#      #+#    */
/*   Solved: 2026/01/14 15:44:45 by hv4564        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int from;
    int to;
    int cost;
};

int Find(int x, vector<int>& parent)
{
    if(x == parent[x]) return x; //부모가 자기 자신이면 자기 자신 return 
    return parent[x] = Find(parent[x], parent); // 부모를 찾아서 재귀 호출
}

void unite(int from, int to, vector<int>& parent)
{
    from = Find(from, parent);
    to = Find(to, parent);

    if(from != to)
    {
        parent[to] = from; // to의 부모를 from으로 변경
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; // N = 집의 개수, M = 길의 개수
    cin >> N >> M;

    vector<Edge> edges;
    for(int i = 0; i < M; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges.push_back({from, to ,cost});
    }

    // 가중치 기준 오름차순 정렬
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) 
    { 
        return a.cost < b.cost;
    });

    vector<int> parent(N + 1, 0);

    for(int i = 1; i <= N; ++i)
    {
        parent[i] = i;
    }

    int total_cost = 0;
    int maxValue = 0;
    int count = 0;

    for(const auto& e : edges)
    {
        if(Find(e.from, parent) == Find(e.to, parent)) // 두 곳의 부모가 같다 == 연결하면 사이클
        {
            continue;
        }

        unite(e.from, e.to, parent);

        total_cost += e.cost;
        maxValue = max(maxValue, e.cost);
        count++;

        if(count == N - 1)
        {
            break;
        }

    }

    cout << total_cost - maxValue << endl;

}