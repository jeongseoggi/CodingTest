#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(const char& a, const char& b)
{
    if(isupper(a) && isupper(b))
    {
        return a > b;
    }
    else if(isupper(a) != 0)
    {
        return false;
    }
    else if(isupper(b) != 0)
    {
        return true;
    }
    
    return a > b;
}


string solution(string s) {
    string answer = "";

    sort(s.begin(), s.end(), compare);
    
    answer = s;
    
    return answer;
}