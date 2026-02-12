#include <bits/stdc++.h>
using namespace std;


string solution(string s)
{
    string answer = "";

    long long maxValue = numeric_limits<long long>::min();
    long long minValue = numeric_limits<long long>::max();


    
    string temp;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ')
        {
            long long value = stoll(temp);
            maxValue = max(value, maxValue);
            minValue = min(value, minValue);
            temp = "";
            continue;
        }
        temp += s[i];
    }


    long long value = stoll(temp);
    maxValue = max(value, maxValue);
    minValue = min(value, minValue);


    answer += to_string(minValue);
    answer += " ";
    answer += to_string(maxValue);

    return answer;
}




