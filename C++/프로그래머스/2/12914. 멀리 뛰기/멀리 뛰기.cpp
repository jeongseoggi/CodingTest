#include <string>
#include <vector>

using namespace std;

long long solution(int n) 
{
    long long answer = 0;
    
    vector<long long> vec {0, 1};
    
    for(int i = 2; i <= n + 1; ++i)
    {
        vec.push_back((vec[i - 2] + vec[i - 1]) % 1234567);
    }
    
    answer = vec[n + 1] % 1234567;
    
    return answer;
}