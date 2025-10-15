#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, int k) 
{
    int answer = 0;
    vector<int> v;
    vector<string> tempVector;

    long long value = 0;
    string temp;


    if (k < 10)
    {
        while (n > 0)
        {
            int value = n % k;
            v.push_back(value);
            n /= k;
        }
    }
    else
    {
        v.push_back(n);
    }
 

    for (auto it = v.rbegin(); it != v.rend(); ++it)
    {
        temp += to_string(*it);
    }

    string addStr;
    for (int i = 0; i < temp.size(); ++i)
    {
        if (temp[i] == '0')
        {
            tempVector.push_back(addStr);
            addStr = "";
        }

        addStr += temp[i];
    }

    if (addStr != "")
    {
        tempVector.push_back(addStr);
    }

   
    bool Find = true;
    for (const string& str : tempVector)
    {
        long long val = stoll(str);
        if (val > 1)
        {
            for (int j = 2; j <= sqrt(val); ++j)
            {
                if (val % j == 0)
                {
                    Find = false;
                }
            }

            if (Find)
            {
                answer++;
            }
        }
    }


    return answer;
}