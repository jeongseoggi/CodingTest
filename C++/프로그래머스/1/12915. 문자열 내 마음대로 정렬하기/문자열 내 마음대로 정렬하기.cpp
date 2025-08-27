#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int index;

bool compare(const string& a, const string& b)
{
    if (a[index] < b[index])
    {
        return true;
    }
    else if (a[index] == b[index])
    {
        return a < b;
    }
    else
    {
        return false;
    }
}

vector<string> solution(vector<string> strings, int n) 
{
    vector<string> answer;
    index = n;
    sort(strings.begin(), strings.end(), compare);

    answer = strings;

    return answer;
}