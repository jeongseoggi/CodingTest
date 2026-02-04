#include <string>
#include <vector>

using namespace std;

string solution(int n) 
{
    string answer = "";

    while (n != 0)
    {
        int value = n % 3;

        if (value == 0)
        {
            value = 4;
            n = n / 3 - 1; // 나머지가 0인 경우에 자리 수 보정
            // 20 가정 -> 20 % 3 = 2 -> 6 % 3 = 0 -> 2 % 3 = 2 -> 2 4 2 (X)
            // 20 가정 -> 20 % 3 = 2 -> 6 % 3 = 0 -> 1 % 3 = 1 -> 1 4 2 (O) 0이 되면 해당 자릿 수의 값이 1이 증가하기 때문에 자리 수 보정을 하는 느낌
        }
        else
        {
            n /= 3;
        }

        answer = to_string(value) + answer;
    }


    return answer;
}
