#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> players, int m, int k) 
{
    int answer = 0;

    queue<pair<int, int>> server;

    for (int i = 0; i < players.size(); ++i)
    {
        if (server.size() != 0)
        {
            while (!server.empty())
            {
                pair<int, int> temp = server.front();
                if (i == temp.second)
                {
                    server.pop();
                }
                else
                {
                    break;
                }
            }
        }

        if (players[i] / m == server.size())
        {
            continue;
        }

        int addServerValue = (players[i] / m) - server.size();


        for (int j = 0; j < addServerValue; ++j)
        {
            server.push({ i, i + k });
            answer++;
        }

    }
    

    return answer;
}