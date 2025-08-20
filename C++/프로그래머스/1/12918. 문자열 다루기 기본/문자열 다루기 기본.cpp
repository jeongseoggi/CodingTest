#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (s.length() == 4 || s.length() == 6)
    {
        for (int i = 0; i < s.length(); i++)
        {
            string ss(1, s[i]);
            try
            {
                int num = stoi(ss);
            }
            catch (exception e)
            {
                return false;
            }
           
        }
    }
    else
    {
        return false;
    }
    return answer;
}