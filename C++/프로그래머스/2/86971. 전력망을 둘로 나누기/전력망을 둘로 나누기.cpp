#include <bits/stdc++.h>

using namespace std;

int answer;

int dfs(int num, int prev, unordered_map<int, vector<int>>& maps, int n)
{
    int sum = 1;

    for (const auto& element : maps[num])
    {
        if (prev != element)
        {
            int count = dfs(element, num, maps, n);
            answer = min(answer, abs((n - count) - count));
            sum += count;
        }
    }

    return sum;
}


int solution(int n, vector<vector<int>> wires)
{
    answer = n;

    unordered_map<int, vector<int>> maps;

    for (const auto& element : wires)
    {
        maps[element[0]].push_back(element[1]);
        maps[element[1]].push_back(element[0]);
    }

    dfs(1, 0, maps, n);

    return answer;
}