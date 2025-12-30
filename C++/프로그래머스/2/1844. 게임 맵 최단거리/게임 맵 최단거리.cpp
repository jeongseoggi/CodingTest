#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;

    vector<pair<int, int>> dist = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    vector<vector<int>> distArr(maps.size(), vector<int>(maps[0].size(), -1));

    queue<pair<int, int>> q;

    distArr[0][0] = 1;
    q.push({0, 0}); // y x

   

    int moveY = 0;
    int moveX = 0;

    while (!q.empty())
    {
        pair<int, int> curPos = q.front();
        q.pop();

        for (int i = 0; i < dist.size(); ++i)
        {
            moveY = curPos.first + dist[i].first;
            moveX = curPos.second + dist[i].second;

            if (moveY < 0 || moveX < 0 || moveY >= maps.size() || moveX >= maps[0].size())
            {
                continue;
            }

            if (maps[moveY][moveX] != 0 && distArr[moveY][moveX] == -1)
            {
                distArr[moveY][moveX] = distArr[curPos.first][curPos.second] + 1;
                q.push({ moveY, moveX });
            }
        }
    }

    return distArr[maps.size() - 1][maps[0].size() - 1];
}