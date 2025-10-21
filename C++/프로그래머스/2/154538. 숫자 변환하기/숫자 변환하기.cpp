#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int solution(int x, int y, int n)
{
    int answer = 0;
    queue<int> q;
    set<int> s;
    bool isStop = false;

    q.push(x);

    while (!q.empty())
    {
        queue<int> v;

        while (!q.empty())
        {
            int value = q.front();
            q.pop();

            if (value == y)
            {
                isStop = true;
                break;
            }

            if (s.find(value * 2) == s.end() && value * 2 <= y)
            {
                s.insert(value * 2);
                v.push(value * 2);
            }

            if (s.find(value * 3) == s.end() && value * 3 <= y)
            {
                s.insert(value * 3);
                v.push(value * 3);
            }

            if (s.find(value + n) == s.end() && value + n <= y)
            {
                s.insert(value + n);
                v.push(value + n);
            }
        }
   
        if (isStop)
        {
            break;
        }
        q = v;
        answer++;
    }

    if (isStop)
    {
        return answer;
    }
    else
    {
        return -1;
    }
}