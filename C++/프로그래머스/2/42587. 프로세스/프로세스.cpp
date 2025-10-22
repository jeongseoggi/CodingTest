#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    int answer = 0;


    queue<pair<int, int>> processQue;
    queue<pair<int, int>> Q;

    for (int i =0 ; i < priorities.size(); ++i)
    {
        Q.push(make_pair(priorities[i], i));
    }


    while (!Q.empty())
    {
        pair<int, int> value = Q.front();
        Q.pop();
        bool isNotBest = false;

        queue< pair<int, int>> temp;

        while (!Q.empty())
        {
            pair<int, int> front = Q.front();
            Q.pop();

            if (value.first < front.first)
            {
                isNotBest = true;
            }
            temp.push(front);

        }


        while (!temp.empty())
        {
            pair<int, int> val = temp.front();
            temp.pop();
            Q.push(val);
        }

        if (isNotBest)
        {
            Q.push(value);
        }
        else
        {
            processQue.push(value);

            if (value.second == location)
            {
                answer = processQue.size();
                break;
            }
        }
    }
    return answer;
}