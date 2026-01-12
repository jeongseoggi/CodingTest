#include <bits/stdc++.h>

using namespace std;

void AddVector(multiset<string>& targetMultiset, set<string>& targetSet, string str1)
{
 
    for (int i = 0; i < str1.size() - 1; ++i)
    {
        char c = str1[i];
        char nextC = str1[i + 1];

        if (isalpha(c) && isalpha(nextC))
        {
            string temp;
            temp += (char)tolower(c);
            temp += (char)tolower(nextC);

            targetMultiset.insert(temp);
            targetSet.insert(temp);
        }
    }
}



int solution(string str1, string str2) 
{
    int answer = 0;

    multiset<string> ms_str1;
    set<string> s_str1;
    multiset<string> ms_str2;
    set<string> s_str2;

    int minValue = 0;
    int maxValue = 0;

    AddVector(ms_str1, s_str1, str1);
    AddVector(ms_str2, s_str2, str2);

    if (ms_str1.size() == 0 && ms_str2.size() == 0)
    {
        return 65536;
    }

    for (auto ele : s_str1)
    {
        if (s_str2.find(ele) != s_str2.end())
        {
            minValue += min(ms_str1.count(ele), ms_str2.count(ele));
            maxValue += max(ms_str1.count(ele), ms_str2.count(ele));
            ms_str2.erase(ele);
            s_str2.erase(ele);
        }
        else
        {
            maxValue += ms_str1.count(ele);
        }
    }

    for (auto ele : s_str2)
    {
        maxValue += ms_str2.count(ele);
    }

    answer = ((float)minValue / maxValue) * 65536;


    return answer;
}