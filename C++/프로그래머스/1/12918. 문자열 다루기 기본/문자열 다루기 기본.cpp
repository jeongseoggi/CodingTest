#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (s.length() == 4 || s.length() == 6)
    {
        for (int i = 0; i < s.length(); i++)
        {
            string ss(1, s[i]);
            try // 문자열 정수형으로 변환시도
            {
                int num = stoi(ss);
            }
            catch (exception e) // 변환 실패 -> 숫자가 아닌 문자로 판단 false 리턴
            {
                return false;
            }
           
        }
    }
    else
    {
        return false;
    }
    return answer;
}
