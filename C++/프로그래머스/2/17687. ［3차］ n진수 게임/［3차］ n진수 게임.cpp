#include <bits/stdc++.h>

using namespace std;


string solution(int n, int t, int m, int p) 
{
    string answer = "";
    int count = 2;
    int num = 1;

    // 튜브가 첫 차례인 경우
    if (p == 1)
    {
        answer += '0';
    }

    while (true)
    {
        if (answer.size() >= t)
        {
            break;
        }

        string s = "";
        int targetVal = num;

        while (targetVal > 0)
        {
            int value = targetVal % n;

            if (value < 10)
            {
                s += (char)('0' + value);
            }
            else
            {
                s += (char)('A' + value - 10);
            }

            targetVal /= n;
        }

        reverse(s.begin(), s.end());

        for (char c : s)
        {
            if (answer.size() >= t)
            {
                break;
            }

            if (count == p)
            {
                answer += c;
            }

            count++;

            if (count > m)
            {
                count = 1;
            }
        }

        num++;
    }



    return answer;
}
