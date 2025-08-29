#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) 
{
    vector<int> answer;

    int lowValue = score[0];
    vector<int> v;
    for (int i = 0; i < score.size(); i++)
    {
        
        v.push_back(score[i]);
        if (i + 1 > k)
        {
            sort(v.begin(), v.end());
            lowValue = v[v.size() - 1];
            for (int j = v.size() - 1; j >= v.size() - k; j--)
            {
                
                if (lowValue > v[j])
                {
                    lowValue = v[j];
                }
            }

        }
        else
        {
            if (lowValue > score[i])
            {
                lowValue = score[i];
            }
        }
        
        answer.push_back(lowValue);
    }


    return answer;
}