#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    int value = 0;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());


    for (int i = 1; i <= n; i++)
    {
        if (find(lost.begin(), lost.end(), i) != lost.end())
        {
            if (find(reserve.begin(), reserve.end(), i) != reserve.end() && value != i)
            {
                value = i;
                answer++;
            }
            continue;
        }
        else
        {
            answer++;
            if (find(reserve.begin(), reserve.end(), i) != reserve.end())
            {
                int prevNum = i - 1;
                int nextNum = i + 1;

                if (prevNum > 0 && value != prevNum)
                {
                    if (find(lost.begin(), lost.end(), prevNum) != lost.end())
                    {
                        if (find(reserve.begin(), reserve.end(), prevNum) != reserve.end())
                        {
                            continue;
                        }

                        value = prevNum;
                        answer++;
                        continue;
                    }
                }

                if (nextNum <= n && value != nextNum)
                {
                    if (find(reserve.begin(), reserve.end(), nextNum) != reserve.end())
                    {
                        continue;
                    }

                    if (find(lost.begin(), lost.end(), nextNum) != lost.end())
                    {
                        value = nextNum;
                        answer++;
                    }
                }
            }
        }
    }
    return answer;
}