#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    
    vector<int> featureDays;

    for (int i = 0; i < progresses.size(); i++)
    {
        int val = 100 - progresses[i]; //70
        
        int featDay = val / speeds[i];

        featureDays.push_back(val % speeds[i] == 0 ? featDay : featDay + 1);
    }


    int value = featureDays[0];
    int feat = 1;
    for (int i = 1; i < featureDays.size(); i++)
    {
        if (value < featureDays[i])
        {
            value = featureDays[i];
            answer.push_back(feat);
            feat = 1;
            continue;
        }

        feat++;
    }

    answer.push_back(feat);

    return answer;
}