#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int& a, const int& b)
{
    return a > b;
}


int solution(int k, int m, vector<int> score)
{
    int answer = 0;

    sort(score.begin(), score.end(), compare);


    int min = score[0];
    int next = 0;
    for (int i = 0; i < score.size(); i++)
    {
        if (min > score[i])
        {
            min = score[i];
        }

        if (next == m - 1)
        {
            answer += min * m;
            next = 0;
            continue;
        }

        next++;
    }


    return answer;
}
