#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> solution(vector<int> answers) 
{
    vector<int> answer;

    vector<int> first({ 1,2,3,4,5 });
    vector<int> second({ 2,1,2,3,2,4,2,5 });
    vector<int> third({ 3,3,1,1,2,2,4,4,5,5 });



    vector<int> corret(3, 0);


    int firstIndex = 0;
    int secondIndex = 0;
    int thirdIndex = 0;

    for (int i = 0; i < answers.size(); i++)
    {
        if (first[firstIndex] == answers[i])
        {
            corret[0]++;
        }
        if (second[secondIndex] == answers[i])
        {
            corret[1]++;
        }
        if (third[thirdIndex] == answers[i])
        {
            corret[2]++;
        }

        ++firstIndex == first.size() ? firstIndex = 0 : firstIndex;
        ++secondIndex == second.size() ? secondIndex = 0 : secondIndex;
        ++thirdIndex == third.size() ? thirdIndex = 0 : thirdIndex;
    }

    int maxnum = *max_element(corret.begin(), corret.end());

    for (int i = 0; i < corret.size(); i++)
    {
        if (maxnum == corret[i])
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}