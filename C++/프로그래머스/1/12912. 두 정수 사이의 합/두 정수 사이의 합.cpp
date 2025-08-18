#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    int addNum = a < b ? a : b;
    for(int i = 0; i <= abs(a - b); i++)
    {
        answer += addNum + i;
    }
    
    
    
    
    return answer;
}