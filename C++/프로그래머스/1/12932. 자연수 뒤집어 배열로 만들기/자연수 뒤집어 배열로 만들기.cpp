#include <string>
#include <vector>


using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    string temp = to_string(n);
    vector<int> tempVector;
    
    for(int i = 0; i < temp.length(); i++)
    {
        string s(1, temp[i]);
        int num = stoi(s);
        tempVector.push_back(num);
    }
    
//     for(int j = 0; j < tempVector.size(); j++)
//     {
//         answer.push_back(tempVector.pop_back());
//     }
    

    for(auto it = tempVector.rbegin(); it != tempVector.rend(); it++)
    {
         answer.push_back(*it);
    }
    
    
    
    return answer;
}