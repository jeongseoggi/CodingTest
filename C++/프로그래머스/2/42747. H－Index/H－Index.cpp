#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(const int& a, const int& b)
{
    return a > b;
}


int solution(vector<int> citations)
{
    int answer = -1;

    sort(citations.begin(), citations.end(), Compare);


    for (int i = 0; i < citations.size(); i++)
    {
        if (i + 1 > citations[i])
        {
            answer = i;
            break;
        }
    }

    
    answer = answer == -1 ? citations.size() : answer;

    return answer;
}
