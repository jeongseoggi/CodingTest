#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";
    vector<string>v{ "RT", "CF", "JM", "AN" };

    map<int, int> scoresMap;
    map<char, int> personalityTestMap;

    scoresMap.insert(make_pair(1, 3));
    scoresMap.insert(make_pair(2, 2));
    scoresMap.insert(make_pair(3, 1));
    scoresMap.insert(make_pair(4, 0));
    scoresMap.insert(make_pair(5, 1));
    scoresMap.insert(make_pair(6, 2));
    scoresMap.insert(make_pair(7, 3));

    personalityTestMap.insert(make_pair('R', 0));
    personalityTestMap.insert(make_pair('T', 0));
    personalityTestMap.insert(make_pair('C', 0));
    personalityTestMap.insert(make_pair('F', 0));
    personalityTestMap.insert(make_pair('J', 0));
    personalityTestMap.insert(make_pair('M', 0));
    personalityTestMap.insert(make_pair('A', 0));
    personalityTestMap.insert(make_pair('N', 0));

    for (int i = 0; i < choices.size(); i++)
    {
        string s = survey[i];
        int score = scoresMap[choices[i]];

        if (choices[i] < 4) // 동의
        {
            //s의 0번째의 값 올리기
            auto it = personalityTestMap.find(s[0]);
            it->second += score;
        }
        else // 비동의
        {
            //s의 1번째의 값 올리기
            auto it = personalityTestMap.find(s[1]);
            it->second += score;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        int firstScore = personalityTestMap[v[i][0]];
        int secScore = personalityTestMap[v[i][1]];

        if (firstScore > secScore)
        {
            answer += v[i][0];
        }
        else if(secScore > firstScore)
        {
            answer += v[i][1];
        }
        else if (firstScore == secScore)
        {
            answer += v[i][0] > v[i][1] ? v[i][1] : v[i][0];
        }

    }


    return answer;
}