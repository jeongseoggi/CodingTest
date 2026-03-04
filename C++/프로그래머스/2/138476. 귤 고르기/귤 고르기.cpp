#include <bits/stdc++.h>

using namespace std;

bool Compare(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) 
{
    int answer = 0;
    int count = k;
    map<int, int> maps;


    for (int& a : tangerine)
    {
        maps[a] += 1;
    }

    vector<pair<int, int>> pairs(maps.begin(), maps.end());
    sort(pairs.begin(), pairs.end(), Compare);

    for (const pair<int, int> p : pairs)
    {
        if (count <= 0) break;
        count -= p.second;
        answer++;
    }


    return answer;
}
