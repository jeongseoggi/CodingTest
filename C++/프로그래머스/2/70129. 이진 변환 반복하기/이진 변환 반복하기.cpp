#include <string>
#include <vector>

using namespace std;

int zeroValue = 0;

int test(string ss, int changeValue)
{
    int oneValue = 0;
    vector<int> v;
    string newStr;
    if (ss.size() <= 1)
    {
        return changeValue;
    }


    for (int i = 0; i < ss.size(); i++)
    {
        if (ss[i] == '0')
        {
            zeroValue++;
            continue;
        }
        oneValue++;
    }

    while (oneValue > 0)
    {
        v.push_back(oneValue % 2);
        oneValue /= 2;
    }

    for (auto it = v.rbegin(); it != v.rend(); it++)
    {
        newStr += to_string(*it);
    }

    return test(newStr, changeValue + 1);
}



vector<int> solution(string s) {
    vector<int> answer;

    answer.push_back(test(s, 0));
    answer.push_back(zeroValue);

    return answer;
}