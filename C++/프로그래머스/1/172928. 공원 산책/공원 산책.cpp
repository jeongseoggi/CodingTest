#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) 
{
    vector<int> answer;

    int dx[] = { 0, 1, 0, -1 }; //SENW
    int dy[] = { 1, 0, -1, 0 }; //SENW

    int xPos = 0;
    int yPos = 0;

    bool isStartFind = false;

    for (int i = 0; i < park.size(); i++)
    {
        if (isStartFind)
        {
            break;
        }
        for (int j = 0; j < park[i].size(); j++)
        {
            if (park[i][j] == 'S')
            {
                yPos = i;
                xPos = j;
                isStartFind = true;
                break;
            }
        }
    }


    for (int i = 0; i < routes.size(); i++)
    {
        string s(1, routes[i][2]);
        int moveIndex = stoi(s);
        int index = 0;
        bool cango = true;

        switch (routes[i][0])
        {
        case 'S':
            index = 0;
            break;
        case 'E':
            index = 1;
            break;
        case 'N':
            index = 2;
            break;
        case 'W':
            index = 3;
            break;
        default:
            break;
        }
        
        for (int k = 1; k <= moveIndex; k++)
        {
            int moveX = xPos + dx[index] * k;
            int moveY = yPos + dy[index] * k;

            if (moveY < 0 || moveY >= park.size() || moveX < 0 || moveX >= park[0].size())
            {
                cango = false;
                break;
            }

            if (park[moveY][moveX] == 'X')
            {
                cango = false;
                break;
            }
        }

        if (cango)
        {
            xPos += dx[index] * moveIndex;
            yPos += dy[index] * moveIndex;
        }


    }

    answer.push_back(yPos);
    answer.push_back(xPos);


    return answer;
}
