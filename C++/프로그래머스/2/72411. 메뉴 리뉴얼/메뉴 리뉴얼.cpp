#include <bits/stdc++.h>

using namespace std;

void makeCourse(vector<char> v, string course, int target, vector<string>& result)
{
    if (course.size() == target)
    {
        result.push_back(course);
        return;
    }

    for (size_t i = 0; i < v.size(); ++i)
    {
        makeCourse(vector<char>(v.begin() + i + 1, v.end()), course + v[i], target, result);
    }
}




vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (int count : course)
    {
        map<string, int> orderCount;

        for (string order : orders)
        {
            vector<char> orderChars(order.begin(), order.end());
            sort(orderChars.begin(), orderChars.end());

            vector<string> combinations;
            makeCourse(orderChars, "", count, combinations);
            

            for (string comb : combinations)
            {
                orderCount[comb]++;
            }
        }

        int maxCount = 0;
        for (const auto& query : orderCount)
        {
            maxCount = max(maxCount, query.second);
        }

        for (const auto& entry : orderCount)
        {
            if (entry.second == maxCount && maxCount >= 2)
            {
                answer.push_back(entry.first);
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}