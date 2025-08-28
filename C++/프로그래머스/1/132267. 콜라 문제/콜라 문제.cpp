#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) 
{
    int answer = 0;

    int num = 0;
    while (a <= n)
    {

        if (n % a != 0)
        {
            num += n % a;
            n = (n / a) * b;
        }
        else
        {
            n = (n / a) * b;
        }

        answer += n;

        if (n < a)
        {
            n += num;
            num = 0;
        }
    }



    return answer;
}