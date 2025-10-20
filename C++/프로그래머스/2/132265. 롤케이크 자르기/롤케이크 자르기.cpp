#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) 
{
    int answer = 0;

    map<int, int> map1;
    map<int, int> map2;

    for (int i = 0; i < topping.size(); ++i)
    {
        map2[topping[i]]++;
    }

    for (int i = 0; i < topping.size(); ++i)
    {
        map1[topping[i]]++;
        map2[topping[i]]--;

        if (map2[topping[i]] == 0)
        {
            map2.erase(topping[i]);
        }

        if (map1.size() == map2.size())
        {
            answer++;
        }
    }

    return answer;
}