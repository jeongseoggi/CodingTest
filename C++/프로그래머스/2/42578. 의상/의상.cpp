#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


int solution(vector<vector<string>> clothes) 
{
    int answer = 0;

    unordered_map<string, int> maps;


    for (int i = 0; i < clothes.size(); i++)
    {
        maps[clothes[i][1]]++;
    }

    
    for (auto it = maps.begin(); it != maps.end(); it++)
    {
        answer = answer == 0 ? (it->second + 1) : answer * (it->second + 1);
    }
    
    answer -= 1;
    return answer;
}