#include <bits/stdc++.h>

using namespace std;

map<int, int> dfs(vector<vector<int>> arr)
{
    int size = arr[0].size();
    int half = size / 2;

    vector<pair<int, int>> area = { {0,0}, {0, size / 2}, {size / 2, 0}, {size / 2, size / 2} };

    map<int, int> result;

    if (half == 1)
    {
        result[arr[0][0]]++;
        result[arr[0][1]]++;
        result[arr[1][0]]++;
        result[arr[1][1]]++;

        return result;
    }


    for (int i = 0; i < area.size(); ++i)
    {
        pair<int, int> range = area[i];

        vector<vector<int>> v(half, vector<int>(half, 0));
        map<int, int> count;

        for (int j = 0; j < half; ++j)
        {
            for (int k = 0; k < half; ++k)
            {
                int curX = k + range.second;
                int curY = j + range.first;

                v[j][k] = arr[curX][curY];
                count[arr[curX][curY]]++;
            }
        }

        if (count[0] == (half * half) || count[1] == (half * half))
        {
            count[0] = count[0] / (half * half);
            count[1] = count[1] / (half * half);
        }
        else
        {
            count = dfs(v);
        }


        result[0] += count[0];
        result[1] += count[1];
    }

    return result;
}


vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;

    map<int, int> maps;

    maps = dfs(arr);

    if (maps[0] == 0)
    {
        return { 0, 1 };
    }
    else if (maps[1] == 0)
    {
        return { 1, 0 };
    }
    return {maps[0], maps[1]};
}