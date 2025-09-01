#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    string answer = "";

    queue<string> card1q;
    queue<string> card2q;

    for (int i = 0; i < cards1.size(); i++)
    {
        card1q.push(cards1[i]);
    }

    for (int i = 0; i < cards2.size(); i++)
    {
        card2q.push(cards2[i]);
    }


    bool isYes = true;
    for (int i = 0; i < goal.size(); i++)
    {
        if (card1q.empty())
        {
            if (card2q.front() != goal[i])
            {
                isYes = false;
                break;
            }
            else
            {
                card2q.pop();
            }
        }
        else if (card2q.empty())
        {
            if (card1q.front() != goal[i])
            {
                isYes = false;
                break;
            }
            else
            {
                card1q.pop();
            }
        }
        else
        {
            if (card1q.front() != goal[i] && card2q.front() != goal[i])
            {
                isYes = false;
                break;
            }
            else
            {
                if (card1q.front() == goal[i])
                {
                    card1q.pop();
                }
                else
                {
                    card2q.pop();
                }
            }
        }
    }

    answer = isYes ? "Yes" : "No";
    return answer;
}