#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    int answer = 0;

    map<string, int> wantsMaps;
    bool isRegister = true;

    for (int i = 0; i < want.size(); i++)
    {
        if (find(discount.begin(), discount.end(), want[i]) == discount.end())
        {
            return answer;
        }
        wantsMaps[want[i]] = number[i];
    }


    for (int i = 0; i < discount.size(); i++)
    {
        map<string, int> maps;

        for (int j = i; j < i + 10; j++)
        {
            if (j >= discount.size())
            {
                break;
            }

            if (wantsMaps.find(discount[j]) == wantsMaps.end())
            {
                break;
            }

            maps[discount[j]]++;
        }

        for (auto it = wantsMaps.begin(); it != wantsMaps.end(); it++)
        {
            isRegister = true;
            string temp = it->first;

            if (wantsMaps[temp] != maps[temp])
            {
                isRegister = false;
                break;
            }
        }

        if (isRegister)
        {
            answer++;
        }
    }
    return answer;
}