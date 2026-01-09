#include <bits/stdc++.h>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second > b.second)
    {
        return true;
    }
    else
    {
        return false;
    }
}


vector<int> solution(string s) 
{
    vector<int> answer;
    string temp = "";

    unordered_map<int, int> maps;


    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] != '{' && s[i] != '}' && s[i] != ',')
        {
            temp += s[i];
        }
        else if ((s[i] == '}' || s[i] == ',') && temp != "")
        {
            int value = stoi(temp);
            maps[value]++;
            temp = "";
        }

    }

    vector<pair<int, int>> pairV(maps.begin(), maps.end());

    sort(pairV.begin(), pairV.end(), Compare);

    for (int i = 0; i < pairV.size(); ++i)
    {
        answer.push_back(pairV[i].first);
    }

    return answer;
}
