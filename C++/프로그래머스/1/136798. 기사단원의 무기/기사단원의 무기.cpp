#include <string>
#include <vector>
#include <cmath>

using namespace std;

int measureCount(int n)
{
    if (n == 1)
    {
        return 1;
    }

    int count = 2;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            count += 2;
            if (i * i == n)
            {
                count--;
            }
        }
    }
    return count;
}





int solution(int number, int limit, int power) 
{
    int answer = 0;

    for (int i = 1; i <= number; i++)
    {
        int value = measureCount(i);

        if (value > limit)
        {
            value = power;
        }

        answer += value;
    }
    return answer;
}