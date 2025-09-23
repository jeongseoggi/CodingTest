#include <iostream>
#include <stdlib.h>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    while (true)
    {
        int aBattle = a % 2 == 0 ? a - 1 : a + 1;
        int bBattle = b % 2 == 0 ? b - 1 : b + 1;

        if (aBattle == b && bBattle == a)
        {
            break;
        }

        if (a % 2 == 1)
        {
            a += 1;
        }
        if (b % 2 == 1)
        {
            b += 1;
        }


        a /= 2;
        b /= 2;
        answer++;
   
    }

    return answer;
}
