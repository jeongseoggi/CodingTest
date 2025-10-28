#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool Compare(string const& a, string const& b)
{
    string aValue = a + b;
    string bValue = b + a;

    return stoll(aValue) > stoll(bValue);
}

string solution(vector<int> numbers) 
{
    string answer = "";

    vector<string> vec;

    for (const int& num : numbers)
    {
        vec.push_back(to_string(num));
    }
    
    sort(vec.begin(), vec.end(), Compare);

    answer = accumulate(vec.begin(), vec.end(), string());

    return answer[0] == '0' ? "0" : answer;
}