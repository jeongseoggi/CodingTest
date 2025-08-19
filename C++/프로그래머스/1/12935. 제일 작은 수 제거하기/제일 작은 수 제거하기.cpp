#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if (arr.size() == 1)
    {
        answer.push_back(-1);
    }
    else
    {
        int val = arr[0];
        int index = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (val > arr[i])
            {
                val = arr[i];
                index = i;
            }
        }
        arr.erase(arr.begin() + index);
        answer = arr;
    }
    return answer;
}