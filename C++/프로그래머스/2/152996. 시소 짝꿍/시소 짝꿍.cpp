#include <bits/stdc++.h>

using namespace std;


long long solution(vector<int> weights) 
{
    long long answer = 0;
    
    sort(weights.begin(), weights.end());

    for (int i = 0; i < weights.size(); ++i)
    {
        for (int j = i + 1; j < weights.size(); ++j)
        {
            if (weights[i] == weights[j])
            {
                answer++;
            }
            else if (weights[i] * 3 == weights[j] * 2)
            {
                answer++;
            }
            else if (weights[i] * 4 == weights[j] * 3)
            {
                answer++;
            }
            else if (weights[i] * 2 == weights[j])
            {
                answer++;
            }
            else if (weights[i] * 2 < weights[j])
            {
                break;
            }
        }
    }

    return answer;
}

