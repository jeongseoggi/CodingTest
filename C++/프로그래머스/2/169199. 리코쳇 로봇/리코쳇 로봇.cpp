#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> maps;

int bfs(pair<int, int> pos)
{
    vector<pair<int, int>> dir = { {-1, 0 }, {1, 0}, {0, -1}, {0, 1} }; // 상 하 좌 우
    set<pair<pair<int, int>, pair<int, int>>> visited;

    queue<pair<pair<int, int>, int>> q;

    q.push({ pos, 0 });

    while (!q.empty())
    {
        pair<int, int> currentPos = q.front().first; // 현재 위치
        int moveCount = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int moveY = currentPos.first + dir[i].first;
            int moveX = currentPos.second + dir[i].second;

            if (moveY >= maps.size() || moveY < 0 || moveX >= maps[0].size() || moveX < 0 || maps[moveY][moveX] == 'D')
            {
                continue;
            }

            while (true)
            {
                moveY += dir[i].first;
                moveX += dir[i].second;

                if (moveY >= maps.size() || moveY < 0 || moveX >= maps[0].size() || moveX < 0 || maps[moveY][moveX] == 'D')
                {
                    moveY -= dir[i].first;
                    moveX -= dir[i].second;

                    if (maps[moveY][moveX] == 'G')
                    {
                        return moveCount + 1;
                    }

                    int value = visited.size();

                    visited.insert(make_pair(currentPos, make_pair(moveY, moveX)));
                    if (value == visited.size()) break;

                    q.push(make_pair(make_pair(moveY, moveX), moveCount + 1));
                    break;

                }

            }
        }
    }

    return -1;
}



int solution(vector<string> board) 
{
    int answer = 0;

    maps.assign(board.size(), vector<char>(board[0].size()));
    pair<int, int> startPos;

    for (int i = 0; i < board.size(); ++i)
    {
        string str = board[i];
        for (int j = 0; j < str.size(); ++j)
        {
            if (str[j] == 'R')
            {
                startPos = { i, j };
            }

            maps[i][j] = str[j];
        }
    }


    return bfs(startPos);
}