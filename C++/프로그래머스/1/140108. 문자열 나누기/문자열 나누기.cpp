#include <string>
#include <vector>

using namespace std;
int solution(string s) 
{
    int answer = 0;

    int correct = 0;
    int notcorrect = 0;

    char firstChar = s[0];
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == firstChar)
        {
            correct++;
        }
        else if (s[i] != firstChar)
        {
            notcorrect++;
        }

        if (correct != notcorrect && i + 1 >= s.size())
        {
            answer++;
        }
        else if (correct == notcorrect)
        {
            answer++;
            firstChar = s[i + 1];
        }
    }



    return answer;
}