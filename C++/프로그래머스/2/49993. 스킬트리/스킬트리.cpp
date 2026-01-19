#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) 
{
    int answer = 0;

    queue<char> q;
    unordered_map<char, int> unMap;
    for (int i = 0; i < skill.size(); ++i)
    {
        q.push(skill[i]);
        unMap[skill[i]]++;
    }

    //CBE

    for (int i = 0; i < skill_trees.size(); ++i)
    {
        string temp = skill_trees[i];
        bool isImpossible = false;

        for (int j = 0; j < temp.size(); ++j)
        {
            if (unMap.find(temp[j]) != unMap.end())
            {
                if (q.front() == temp[j])
                {
                    char c = q.front();
                    q.pop();
                    q.push(c);
                }
                else
                {
                    isImpossible = true;
                    break;
                }
            }
        }

        if (!isImpossible)
        {
            answer++;
        }

        while (q.front() != skill[0])
        {
            char c = q.front();
            q.pop();
            q.push(c);
        }
    }



    return answer;
}