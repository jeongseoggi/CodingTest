#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> order) 
{
    int answer = 0;
    int index = 0;
    stack<int> s;

    
    for (int i = 1; i <= order.size(); ++i)
    {
        s.push(i);

        while (!s.empty() && order[index] == s.top())
        {
            s.pop();
            index++;
            answer++;
        }
    }
    return answer;
}