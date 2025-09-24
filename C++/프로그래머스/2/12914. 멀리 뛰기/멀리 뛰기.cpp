#include <string>
#include <vector>

using namespace std;

long long solution(int n) 
{
    long long answer = 0;

    vector<long long> pibo{ 0, 1 };

    for (int i = 2; i <= n + 1; i++)
    {
        pibo.push_back((pibo[i - 2] + pibo[i - 1]) % 1234567);
    }

    answer = pibo[n + 1] % 1234567;

    return answer;
}