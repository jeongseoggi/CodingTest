#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    
    int count = 1;
    int zeroRemove = 0;


    while (s.size() != 1)
    {
        string temp;
        int oneValue;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '1')
            {
                temp += s[i];
            }
            else
            {
                zeroRemove++;
            }
        }

        oneValue = temp.size();
        temp.clear();

        while (oneValue != 0)
        {
            int div = oneValue % 2;
            temp += to_string(div);
            oneValue /= 2;
        }
        
        if (temp.size() == 1)
        {
            break;
        }

        s = temp;

        count++;
    }


    answer.push_back(count);
    answer.push_back(zeroRemove);

    return answer;
}