#include <string>
#include <vector>

using namespace std;

int test(string t, string p, int index, int answer)
{
    string temp;

    if (index + p.length() > t.length())
    {
        return answer;
    }

    for (int i = index; i < p.length() + index; i++)
    {
        temp += t[i];
    }

    long long num = stoll(p);
    long long tNum = stoll(temp);

    if (num >= tNum)
    {
        answer++;
    }

    return test(t, p, ++index, answer);
}

int solution(string t, string p) 
{
    int answer = 0;

    answer = test(t, p, 0, answer);

    return answer;
}