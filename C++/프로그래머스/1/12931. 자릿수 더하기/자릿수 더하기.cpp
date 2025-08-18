#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string temp = to_string(n);
    
    
    for(int i = 0; i < temp.length(); i++)
    {
        string s(1, temp[i]);
        int num = stoi(s);
        answer += num;
    }
    

    return answer;
}