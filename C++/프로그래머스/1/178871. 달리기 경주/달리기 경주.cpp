#include <string>
#include <vector>
#include <map>

using namespace std;
vector<string> solution(vector<string> players, vector<string> callings) 
{
    vector<string> answer;
    map<string, int> maps;

    for (int i = 0; i < players.size(); i++)
    {
        maps.insert(make_pair(players[i], i));
    }


    for (int i = 0; i < callings.size(); i++)
    {
        int index = maps[callings[i]];

        if (index > 0)
        {
            string temp = players[index - 1];

            players[index - 1] = players[index];
            players[index] = temp;

            maps[callings[i]] = index - 1;
            maps[temp] = index;
        }
    }

    for (const string& player : players)
    {
        answer.push_back(player);
    }


    return answer;
}
