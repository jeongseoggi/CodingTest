#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while (n > 0) // 2로 나누고 나머지가 0이면 그냥 순간이동 선택, 나머지가 1이면 1칸 이동 및 n--
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else if(n % 2 != 0)
        {
            n--;
            ans++;
        }
    }
    return ans;
}