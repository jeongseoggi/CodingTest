#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool comapre(const int& a, const int& b)
{
    return a > b;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
    vector<int> answer;

    map<int, int> maps;

    maps.insert(make_pair(6, 1));
    maps.insert(make_pair(5, 2));
    maps.insert(make_pair(4, 3));
    maps.insert(make_pair(3, 4));
    maps.insert(make_pair(2, 5));


    sort(lottos.begin(), lottos.end(), comapre);
    sort(win_nums.begin(), win_nums.end(), comapre);

    int corretCount = 0;
    int zeroCount = 0;
    for (int i = 0; i < lottos.size(); i++)
    {
        if (find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end())
        {
            corretCount++;
        }

        if (lottos[i] == 0)
        {
            zeroCount++;
        }
    }

    int low = maps.find(corretCount) != maps.end() ? maps[corretCount] : 6;
    int high = maps.find(corretCount + zeroCount) != maps.end() ? maps[corretCount + zeroCount] : 6;

    answer.push_back(high);
    answer.push_back(low);
    return answer;
}