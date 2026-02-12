#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    string answer = "";
    bool isFirst = true;


    for (int i = 0; i < s.size(); ++i)
    {
        if (isFirst && isalpha(s[i]))
        {
            s[i] = toupper(s[i]);
            isFirst = false;
        }
        else if (!isalpha(s[i]))
        {
            isFirst = false;
        }
        else if (!isFirst && isupper(s[i]))
        {
            s[i] = tolower(s[i]);
        }


        if (s[i] == ' ')
        {
            isFirst = true;
        }
    }

    return s;
}
