#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    string answer = "";

    bool isFirst = true;

    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0 || isFirst)
        {
            if (s[i] >= 'A')
            {
                s[i] = toupper(s[i]);
                isFirst = false;
                continue;
            }
            else if (s[i] == ' ')
            {
                continue;
            }
            else
            {
                isFirst = false;
                continue;
            }
        }
        
        if (s[i] == ' ')
        {
            isFirst = true;
        }

        if (!isFirst)
        {
            s[i] = tolower(s[i]);
        }
        
    }

    answer = s;


    return answer;
}
