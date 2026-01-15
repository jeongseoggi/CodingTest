/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4386                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: hv4564 <boj.kr/u/hv4564>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4386                           #+#        #+#      #+#    */
/*   Solved: 2026/01/15 09:52:09 by hv4564        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Edge
{
    int u;
    int v;
    double w;
};

int find(int x, vector<int>& parent)
{
    if(x == parent[x]) return x;
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
    int N;

    cin >> N;

    vector<pair<double, double>> p(N);
    vector<Edge> edges;

    for(int i =0 ; i < N; ++i)
    {
        cin >> p[i].first >> p[i].second;
    }


    for(int i = 0; i < N; ++i)
    {
        for(int j = i + 1; j < N; ++j)
        {
            double w = hypot(p[i].first - p[j].first, p[i].second - p[j].second);
            edges.push_back({i, j, w});
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)
    {
        return a.w < b.w;
    });

    vector<int> parent(N, 0);

    for(int i = 0; i < N; ++i)
    {
        parent[i] = i;
    }

    double total_cost = 0;
    int count = 0;

    for(const auto& e : edges)
    {
        if(find(e.u, parent) == find(e.v, parent))
        {
            continue;
        }

        unite(e.u, e.v, parent);

        total_cost += e.w;
        count++;

        if(count == N - 1)
        {
            break;
        }
    }

   cout << fixed << setprecision(2) << total_cost << "\n";
} 