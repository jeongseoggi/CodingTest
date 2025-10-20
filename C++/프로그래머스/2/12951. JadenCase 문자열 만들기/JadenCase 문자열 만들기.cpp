#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    bool isFirst = true;

    for (int i = 0; i <= s.size(); ++i)
    {
        if (isFirst && isalpha(s[i]))
        {
            s[i] = toupper(s[i]);
            isFirst = false;
        }
        else if (!isFirst)
        {
            s[i] = tolower(s[i]);
        }
        else
        {
            isFirst = false;
        }

        if (isspace(s[i]))
        {
            isFirst = true;
        }
    }

    answer = s;


    return answer;
}

