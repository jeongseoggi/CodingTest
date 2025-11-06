#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) 
{
    vector<int> answer;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
    vector<pair<int, int>> dir = { {1,0 }, {0, 1}, {-1, -1} };

    int x = 0;
    int y = 0;
    int dirIndex = 0;
    int cnt = 1;

    int temp = n;

    while (temp > 0)
    {
        for (int i = 0; i < temp; ++i)
        {
            y = y + dir[dirIndex].first >= arr.size() ? y : y + dir[dirIndex].first;
            x = x + dir[dirIndex].second >= arr.size() ? x : x + dir[dirIndex].second;

            if (visited[y][x] == false)
            {
                arr[y][x] = cnt;
                visited[y][x] = true;
                cnt++;
            }
        }

        dirIndex++;

        if (dirIndex >= dir.size())
        {
            dirIndex = 0;
        }
        temp--;
       
    }


    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr[0].size(); ++j)
        {
            if (arr[i][j] != 0)
            {
                answer.push_back(arr[i][j]);
            }
        }
    }

    return answer;
}