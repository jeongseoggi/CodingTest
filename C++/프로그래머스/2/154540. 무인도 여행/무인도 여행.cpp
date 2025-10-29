#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<string> mapVec;


int FindIsland(pair<int, int> pos, vector<vector<bool>>& visited)
{
    int count = 0;
    queue<pair<int, int>> q;
    vector<pair<int,int>> dir({ {1, 0}, {-1, 0 }, {0, 1}, {0, -1} });

    q.push(pos);

    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();

        if (mapVec[pos.first][pos.second] != 'X' && visited[pos.first][pos.second] == false)
        {
 
            count += mapVec[pos.first][pos.second] - '0';
            visited[pos.first][pos.second] = true;
        }
        else
        {
            continue;
        }

        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> nextPos = { pos.first + dir[i].first, pos.second + dir[i].second };

            if (nextPos.first >= 0 && nextPos.first < mapVec.size() && nextPos.second >= 0 && nextPos.second < mapVec[0].size() && visited[nextPos.first][nextPos.second] == false)
            {
                if (mapVec[nextPos.first][nextPos.second] == 'X')
                {
                    continue;
                }
                q.push(nextPos);
            }
        }
    }

    return count;

}

vector<int> solution(vector<string> maps) 
{
    vector<int> answer;
    mapVec = maps;

    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));

    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[0].size(); ++j)
        {
            if (visited[i][j])
            {
                continue;
            }
            int result = FindIsland({i,j}, visited);

            if (result != 0)
                answer.push_back(result);
        }
    }

    if (answer.empty())
    {
        answer.push_back(-1);
    }
    else
    {
        sort(answer.begin(), answer.end());
    }


    return answer; 
}