#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) 
{
    string answer = "";

    char changeChar;

    for (int i = 0; i < s.size(); i++)
    {
        int findSkip = 0;
        for (int j = 1; j <= index + findSkip; j++)
        {
            int addChar = s[i] + j;
            if (addChar > 'z')
            {
                int val = s[i] + j;
                val -= 'a';
                val %= 26;
                addChar = 'a' + val;
            }

            char c = addChar;
            
            if (skip.find(c) != string::npos)
            {
                findSkip++;
                continue;
            }

            changeChar = c;
        }

        answer += changeChar;
    }
    return answer;
}
