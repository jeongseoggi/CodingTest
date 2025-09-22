#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int value = brown + yellow;

    for (int i = 3; i <= value; ++i)
    {
        if (value % i == 0)
        {
            int num = value / i;

            if ((i - 2) * (num - 2) == yellow) // 테두리 제외 계산 i - 2, num - 2 == yellow
            {
                answer.push_back(num);
                answer.push_back(i);
                break;
            }
        }
    }
    return answer;
}