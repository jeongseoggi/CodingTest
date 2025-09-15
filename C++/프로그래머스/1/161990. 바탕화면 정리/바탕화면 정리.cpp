#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper)
{
    vector<int> answer;

    vector<vector<int>> background(wallpaper.size(), vector<int>(0));

    for (int i = 0; i < wallpaper.size(); i++)
    {
        for (int j = 0; j < wallpaper[i].size(); j++)
        {
            if (wallpaper[i][j] == '.')
            {
                background[i].push_back(0);
            }
            else
            {
                background[i].push_back(1);
            }
        }
    }


    int minXY[1][2] = { {99, 99} }; // 1,3
    int maxXY[1][2] = { {0, 0} }; // 4, 7


    for (int y = 0; y < background.size(); y++)
    {
        for (int x = 0; x < background[y].size(); x++)
        {
            if (background[y][x] == 1)
            {
                if (minXY[0][0] > y)
                {
                    minXY[0][0] = y;
                }
                if (minXY[0][1] > x)
                {
                    minXY[0][1] = x;
                }

                if (maxXY[0][0] < y)
                {
                    maxXY[0][0] = y;
                }
                if (maxXY[0][1] < x)
                {
                    maxXY[0][1] = x;
                }
            }
        }
    }


    answer.push_back(minXY[0][0]);
    answer.push_back(minXY[0][1]);

    maxXY[0][0] += 1;
    maxXY[0][1] += 1;
    answer.push_back(maxXY[0][0]);
    answer.push_back(maxXY[0][1]);

    return answer;
}