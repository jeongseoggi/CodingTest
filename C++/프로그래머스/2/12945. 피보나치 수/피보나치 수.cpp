#include <bits/stdc++.h>

using namespace std;

long long solution(int n)
{
    long long answer = 0;

    vector<long long> vec;
    vec.push_back(0);
    vec.push_back(1);

    for (int i = 2; i <= n; ++i)
    {
        vec.push_back((vec[i - 2] + vec[i - 1]) % 1234567);
    }

    answer = vec[n] % 1234567;

    return answer;
}