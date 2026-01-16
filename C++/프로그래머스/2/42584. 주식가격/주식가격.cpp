#include <bits/stdc++.h>

using namespace std;


vector<int> solution(vector<int> prices) {
    vector<int> answer;

    queue<pair<int, int>> q;

    int pricesSize = prices.size();

    for (int i = 0; i < prices.size(); ++i)
    {
        q.push({i, prices[i]});
    }

    bool isNotDownPrice = true;

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        int curPrice = temp.second;



        for (int i = temp.first + 1; i < prices.size(); ++i)
        {
            if (curPrice > prices[i])
            {
                answer.push_back(abs(temp.first - i));
                isNotDownPrice = false;
                break;
            }
        }

        if (isNotDownPrice)
        {
            answer.push_back(abs(temp.first + 1 - pricesSize));
        }

        isNotDownPrice = true;
    }


    return answer;
}
