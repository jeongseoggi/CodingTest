#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    string temp = "";
    for (int i = 1; i < food.size(); i++) 
    {
        int count = 0;
        if (food[i] % 2 == 1)
        {
            if (food[i] - 1 < 0)
                break;

            count = (food[i] - 1) / 2;
        }
        else
        {
            count = food[i] / 2;
        }

        for (int j = 0; j < count; j++)
        {
            temp += to_string(i);
        }
    }

    answer += temp + to_string(0);
    reverse(temp.begin(), temp.end());
    answer += temp;
    return answer;
}