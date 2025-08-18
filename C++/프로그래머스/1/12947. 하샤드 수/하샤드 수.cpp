#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int addValue = 0;
    
    string temp = to_string(x);
    
    for(int i = 0; i < temp.length(); i++)
    {
        string s(1, temp[i]);
        addValue += stoi(s);
    }
    
    if(x % addValue != 0)
    {
        answer = false;
    }
    
    return answer;
}