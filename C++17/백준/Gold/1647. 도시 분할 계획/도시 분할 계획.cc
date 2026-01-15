#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int from;
    int to;
    int cost;
};

int find(int x, vector<int>& parent)
{
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

void unite(int a, int b, vector<int>& parent)
{
    a = find(a, parent);
    b = find(b, parent);
    if(a != b)
    {
        parent[b] = a;
    }
}


int main()
{
    int N, M;

    cin >> N >> M;

    vector<Edge> edges;

    for(int i = 0; i < M; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges.push_back({from, to, cost});
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)
    {
        return a.cost < b.cost;
    });


    vector<int> parent(N + 1);

    for(int i = 1; i <= N; ++i)
    {
        parent[i] = i;
    }

    int total_cost = 0;
    int maxCost = 0;
    int count = 0;

    for(auto& e : edges)
    {
        if(find(e.from, parent) == find(e.to, parent))
        {
            continue;
        }

        unite(e.from, e.to, parent);

        total_cost += e.cost;
        maxCost = max(maxCost, e.cost);
        count++;

        if(count == N - 1)
        {
            break;
        }
    }

    cout << total_cost - maxCost << endl;

}