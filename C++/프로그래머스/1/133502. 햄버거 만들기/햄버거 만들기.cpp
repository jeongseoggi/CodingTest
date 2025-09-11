#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) 
{
    int answer = 0;
    vector<int> v;

    for (int i = 0; i < ingredient.size(); i++)
    {
        v.push_back(ingredient[i]);

        if (v.size() >= 4)
        {
            int idx = v.size();
            if (v[idx - 4] == 1 && v[idx - 3] == 2 && v[idx - 2] == 3 && v[idx - 1] == 1) // 4이상 > 현재위치 ~ 현재 위치 -4 까지 검사
            {
                answer++;

                //찾으면 v에서 제거
                for (int j = 0; j < 4; j++) 
                {
                    v.pop_back();
                }
            }
        }
    }


    return answer;
}
