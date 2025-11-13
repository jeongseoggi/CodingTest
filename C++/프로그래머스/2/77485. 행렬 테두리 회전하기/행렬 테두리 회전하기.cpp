#include <string>
#include <vector>

using namespace std;
int TurnArray(vector<vector<int>>& v, vector<int> query)
{
    int moveCount = 0;
    vector<pair<int, int>> dir = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    int minValue = 99999;

    int y = query[0] - 1;
    int x = query[1] - 1;

    int prevValue = v[y][x];

    while (moveCount < dir.size())
    {
        int nextY = y + dir[moveCount].first;
        int nextX = x + dir[moveCount].second;

        if (nextY >= query[2] || nextX >= query[3] || nextY < query[0] - 1 || nextX < query[1] - 1)
        {
            moveCount++;
            continue;
        }
        else
        {
            minValue = min(minValue, prevValue);

            int temp = v[nextY][nextX];
            v[nextY][nextX] = prevValue;
            prevValue = temp;
        }

        y = nextY;
        x = nextX;
    }

    return minValue;
}


vector<int> solution(int rows, int columns, vector<vector<int>> queries) 
{
    vector<int> answer;

    vector<vector<int>> v(rows, vector<int>(columns, 0));

    int count = 1;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            v[i][j] = count;
            count++;
        }
    }

    for (auto& query : queries)
    {
        answer.push_back(TurnArray(v, query));
    }

    return answer;
}