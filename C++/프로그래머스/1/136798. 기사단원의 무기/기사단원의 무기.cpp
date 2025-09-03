#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) 
{
    int answer = 0;

    for (int i = 1; i <= number; i++)
    {
        int value = i == 1 ? 1 : 2;

        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                value++;
            }
        }

        if (value > limit)
        {
            value = power;
        }
        answer += value;
    }

    return answer;
}