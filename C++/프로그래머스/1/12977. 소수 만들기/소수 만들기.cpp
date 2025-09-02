#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                int num = nums[i] + nums[j] + nums[k];
                int test = sqrt(num);
                bool isBool = false;
                for (int u = 2; u <= test; u++)
                {
                    if (num % u == 0)
                    {
                        isBool = false;
                        break;
                    }
                    else
                    {
                        isBool = true;
                    }
                }
                if (isBool)
                {
                    answer++;
                }
            }
        }
    }
    return answer;
}
