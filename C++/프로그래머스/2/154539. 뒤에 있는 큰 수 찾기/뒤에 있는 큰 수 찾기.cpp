#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer(numbers.size(), -1);
    stack<int> stack;

    stack.push(numbers[numbers.size() - 1]);

    for (int i = numbers.size() - 2; i >= 0; --i)
    {
        bool found = false;
        while (!stack.empty())
        {
            int num = stack.top();
            stack.pop();
            
            if (numbers[i] < num)
            {
                found = true;
                answer[i] = num;
                break;
            }
        }

        if (found)
        {
            stack.push(answer[i]);
        }

        stack.push(numbers[i]);
    }


    return answer;
}