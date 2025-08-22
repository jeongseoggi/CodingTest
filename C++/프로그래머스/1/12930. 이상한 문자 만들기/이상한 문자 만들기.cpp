#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


string solution(string s) 
{
    string answer = "";

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int index = 0;
    int i = 0;
    while (s.length() > i)
    {
        if (s[i] == ' ')
        {
            answer += s[i];
            index = 0;
        }
        else if (index == 0 || index % 2 == 0)
        {
            answer += toupper(s[i]);
            index++;
        }
        else
        {
            answer += s[i];
            index++;
        }
        i++;
    }

    return answer;
}