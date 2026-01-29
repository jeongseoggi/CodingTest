#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> mapVec;


int findMaze(char Target, pair<int, int>& Pos)
{
    vector<pair<int, int>> direction = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    vector<vector<bool>> visited(mapVec.size(), vector<bool>(mapVec[0].size(), false));

    queue<pair<pair<int, int>, int>> q;

    q.push({ Pos, 0 });

    visited[Pos.second][Pos.first] = true;

    while (!q.empty())
    {
        pair<pair<int, int>, int> temp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = temp.first.first + direction[i].first;
            int nextY = temp.first.second + direction[i].second;

            if (!(nextX >= 0 && nextY >= 0 && nextX < mapVec[0].size() && nextY < mapVec.size()))  continue;
            if (mapVec[nextY][nextX] == 'X') continue;
            if (visited[nextY][nextX] == true) continue;

            if (mapVec[nextY][nextX] == Target)
            {
                Pos = make_pair(nextX, nextY);

                return temp.second + 1;
            }

            q.push(make_pair(make_pair(nextX, nextY), temp.second + 1));
            visited[nextY][nextX] = true;
        }
    }

    return -1;

}


int solution(vector<string> maps) 
{
    int answer = 0;

    mapVec = vector<vector<char>>(maps.size(), vector<char>(maps[0].size()));

    pair<int, int> Pos;

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].size(); j++)
        {
            mapVec[i][j] = maps[i][j];
            if (maps[i][j] == 'S')
                Pos = make_pair(j, i);
        }
    }

    int resultL = findMaze('L', Pos);
    if (resultL == -1)
        return -1;

    int resultE = findMaze('E', Pos);
    if (resultE == -1)
        return -1;

    return resultL + resultE;
}

