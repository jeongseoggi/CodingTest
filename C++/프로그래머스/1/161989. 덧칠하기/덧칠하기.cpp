#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int answer = 0;

    map<int, bool> maps;

    for (int i = 0; i < section.size(); i++)
    {
        maps.insert(make_pair(section[i], false));
    }

    for (int i = 0; i < section.size(); i++)
    {
        int sectionValue = section[i];
        if (maps[sectionValue] == true)
        {
            continue;
        }
        int value = sectionValue + (m - 1) > n ? n + 1  : sectionValue + (m - 1);
        bool isFind = false;
        for (int j = sectionValue; j <= value; j++)
        {
            if (maps.find(j) != maps.end() && maps[j] == false)
            {
                maps[j] = true;
                isFind = true;
            }
        }

        if (isFind)
        {
            answer++;
        }
    }


    return answer;
}
