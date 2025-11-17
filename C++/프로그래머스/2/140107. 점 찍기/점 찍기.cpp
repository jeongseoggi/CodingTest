#include <bits/stdc++.h>

using namespace std;

long long PowFunc(const long long value)
{
    return value * value;
}

long long solution(int k, int d) 
{
    long long answer = 0;
    long long y = 0;
    long long radius = PowFunc(d);

    for (int i = 0; i <= d; i += k)
    {
        y = sqrt(radius - PowFunc(i));
        answer += y / (long long)k + 1;
    }

    return answer;
}