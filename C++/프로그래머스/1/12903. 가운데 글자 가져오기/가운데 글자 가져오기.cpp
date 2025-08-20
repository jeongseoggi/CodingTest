#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int strLen = s.length();
    
    if(strLen % 2 == 0)
    {
        answer = s[strLen / 2 - 1];
        answer += s[strLen / 2];
    }
    else
    {
        answer = s[strLen / 2];
    }   
    return answer;
}