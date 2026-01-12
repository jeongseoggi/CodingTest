#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int from;
    int to;
    int cost;
};


bool Compare(Edge a, Edge b)
{
    return a.cost < b.cost;
}

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
    int V, E;

    cin >> V >> E;

    vector<Edge> edges;

    for(int i = 0; i < E; ++i)
    {
        int from, to, cost;

        cin >> from >> to >> cost;

        edges.push_back({from, to, cost});
    }

    sort(edges.begin(), edges.end(), Compare);

    vector<int> parent(V + 1);
    
    for(int i = 1; i <= V; ++i)
    {
        parent[i] = i;
    }

    int total_cost = 0;
    int count = 0;

    for(const auto& e : edges)
    {
        if(find(e.from, parent) == find(e.to, parent))
        {
            continue;
        }
        unite(e.from, e.to, parent);
        total_cost += e.cost;
        count++;

        if(count == V - 1) 
        {
            break;
        }
    }

    cout << total_cost << endl;


    return 0;
}