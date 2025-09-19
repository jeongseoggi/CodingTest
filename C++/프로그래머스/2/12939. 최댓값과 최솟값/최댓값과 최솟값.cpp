#include <string>
#include <vector>
#include <limits>
using namespace std;


string solution(string s) 
{
    string answer = "";

    long long min = numeric_limits<long long>::max();
    long long max = numeric_limits<long long>::min();

    while (true)
    {
        size_t pos = s.find(" ");

        if (pos == string::npos)
        {
            long long value = stoll(s);

            if (value < min)
            {
                min = value;
            }

            if (value > max)
            {
                max = value;
            }
            break;
        }

        string ss = s.substr(0, pos);
        s.erase(0, pos + 1);

        long long value = stoll(ss);

        if (value < min)
        {
            min = value;
        }

        if (value > max)
        {
            max = value;
        }
    }
        
    answer += to_string(min);
    answer += " ";
    answer += to_string(max);


    return answer;
}




