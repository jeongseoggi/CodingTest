#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    
    for(int i = 2; i <= n; ++i)
    {
        int value = (vec[i-2] + vec[i - 1]) % 1234567;
        vec.push_back(value);
    }
    
    answer = vec[n] % 1234567;

    return answer;
}