#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 1234567890;
    
    int val = 0;
    for(int i = 0; i < a.size(); i++)
    {
        val += a[i] * b[i];
    }
    
    answer = val;
    
    return answer;
}