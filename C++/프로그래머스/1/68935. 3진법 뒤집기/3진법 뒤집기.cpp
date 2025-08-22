#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> s;

int test(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        s.push(n % 3);
        return test(n / 3);
    }
}

int solution(int n) {
    int answer = 0;
    test(n);
    
    int power = 1;
    while (!s.empty())
    {
        if (s.top() == 0)
        {
            s.pop();
        }
        else
        {
            int num = s.top();
            answer += num * power;
            s.pop();
        }
         power *= 3;
    }


    return answer;
}