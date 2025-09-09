#include <string>
#include <vector>

using namespace std;

int findMinIndex(char c, string keyMapStr)
{
    int index = 99;
    for (int j = 0; j < keyMapStr.size(); j++)
    {
        if (keyMapStr[j] == c)
        {
            index = j + 1;
            break;
        }
    }
    return index;
}

vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    vector<int> answer;

    int findIndex = 99;
    int added = 0;
    for (int i = 0; i < targets.size(); i++)
    {
        for (int j = 0; j < targets[i].size(); j++)
        {
            for (int k = 0; k < keymap.size(); k++)
            {
                int index = findMinIndex(targets[i][j], keymap[k]);
                findIndex = findIndex > index ? index : findIndex;
            }

            if (findIndex == 99)
            {
                added = 99;
                break;
            }
            else
            {
                added += findIndex;
            }

            findIndex = 99;
        }

        if (added != 99)
        {
            answer.push_back(added);
        }
        else
        {
            answer.push_back(-1);
        }

        added = 0;
    }
    return answer;
}