#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}


int solution(int k, vector<int> tangerine)
{
    int answer = 0;
    int count = k;
    unordered_map<int, int> maps;

    for (int i = 0; i < tangerine.size(); i++)
    {
        maps[tangerine[i]] += 1;
    }

    vector<pair<int, int>> v(maps.begin(), maps.end());
    sort(v.begin(), v.end(), Compare);

    for (const pair<int, int>& pa : v)
    {
        if(count <= 0)
        {
            break;
        }
        
        count -= pa.second;
        answer++;
    }


    return answer;
}