#include <string>
#include <vector>

using namespace std;

vector<string> v = { "aya", "ye", "woo", "ma" };

bool IsContains(string text)
{
    string temp;

    if (text.empty())
    {
        return true;
    }

    for (int j = 0; j < v.size(); j++)
    {
        size_t fir_pos = text.find(v[j]);

        if (fir_pos != string::npos && fir_pos == 0)
        {
            temp = v[j];

            size_t sec_pos = text.find(temp);

            if (sec_pos != string::npos)
            {
                string subTemp = text.erase(sec_pos, temp.length());

                size_t thrid_pos = subTemp.find(temp);

                if (thrid_pos != string:: npos && thrid_pos == 0)
                {
                    return false;
                }
                return IsContains(subTemp);
            }
            else
            {
                return false;
            }
        }
    }

    return false;
}

int solution(vector<string> babbling) 
{
    int answer = 0;

  


    for (int i = 0; i < babbling.size(); i++)
    {
        if (IsContains(babbling[i]))
        {
            answer++;
        }
    }
    return answer;
}
