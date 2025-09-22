#include <string>
#include <vector>

using namespace std;

unsigned long long solution(int n)
{
    unsigned long long answer = 0;

    vector<unsigned long long> pibo;
    pibo.push_back(0);
    pibo.push_back(1);

    for (int i = 2; i <= n; i++)
    {
        pibo.push_back((pibo[i - 2] + pibo[i - 1]) % 1234567);
    }

    answer = pibo[n] % 1234567;


    return answer;
}

