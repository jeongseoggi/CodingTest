#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;

    vector<int> newVec;


    for (int i = 0; i < commands.size(); i++)
    {
        newVec.clear();
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
        {
            newVec.push_back(array[j]);
        }

        sort(newVec.begin(), newVec.end());
        answer.push_back(newVec[commands[i][2] - 1]);
     }


    return answer;
}