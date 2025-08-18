#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int index = 1;
    while(answer.size() < n)
    {
        answer.push_back(x * index);
        index++;
    }
    return answer;
}