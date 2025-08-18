#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const char& a, const char& b)
{
    return a > b;
}

long long solution(long long n) {
    long long answer = 0;
    vector<char> vec;
    string s;

    string temp = to_string(n);

    for (int i = 0; i < temp.length(); i++)
    {
        vec.push_back(temp[i]);
    }

    sort(vec.begin(), vec.end(), compare);


    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        string vecStr(1, *it);
        s += vecStr;
    } 

    answer = stoll(s);

    return answer;
}


