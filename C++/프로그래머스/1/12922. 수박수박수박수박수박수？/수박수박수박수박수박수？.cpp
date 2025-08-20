#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<string> vc({"수", "박"});
    
    for(int i = 0; i < n; i++)
    {
        answer += vc[i % vc.size()];
    }
    
    return answer;
}