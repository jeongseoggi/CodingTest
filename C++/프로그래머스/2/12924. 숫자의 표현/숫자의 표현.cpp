#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;

    int total = 0;
    int start = 1;

    while (start != n)
    {
        int startCount = start;
        while (true)
        {
            total += startCount;
            if (total == n)
            {
                answer++;
                break;
            }
            else if (total > n)
            {
                break;
            }

            startCount++;
        }
        total = 0;
        start++;
    }



    return answer + 1;
}