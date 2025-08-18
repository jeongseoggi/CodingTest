#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    
    int num = 0;
    for(int i = 0 ; i < seoul.size(); i++)
    {
        if(seoul[i].compare("Kim") == 0)
        {
            num = i;
            answer = "김서방은 " + to_string(num) + "에 있다";
            break;
        }
    }
    
    return answer;
}