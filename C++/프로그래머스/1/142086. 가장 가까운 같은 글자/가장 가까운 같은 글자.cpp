#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) 
{
    vector<int> answer;

    answer.push_back(-1);

    for (int i = 1; i < s.length(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (s[i] == s[j - 1])
            {
                answer.push_back((i - j) + 1);
                break;
            }

            if (j - 1 == 0)
            {
                answer.push_back(-1);
            }
        }
    }


    return answer;
}