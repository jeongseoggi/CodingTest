#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) 
{
    int answer = 0;

    for (int i = 0; i < s.size(); i++)
    {
        s.push_back(s[0]);
        s.erase(0, 1);

        stack<char> stack;

        for (int j = 0; j < s.size(); j++)
        {
            if (stack.empty())
            {
                stack.push(s[j]);
            }
            else
            {
                if (stack.top() == '{' && s[j] == '}')
                {
                    stack.pop();
                }
                else if (stack.top() == '[' && s[j] == ']')
                {
                    stack.pop();
                }
                else if (stack.top() == '(' && s[j] == ')')
                {
                    stack.pop();
                }
                else
                {
                    stack.push(s[j]);
                }
            }
        }

        if (stack.empty())
        {
            answer++;
        }
    }


    return answer;
}