#include <bits/stdc++.h>

using namespace std;

int answer;

void dfs(vector<int>& numbers, int target, int index, int currentValue)
{

    if (index >= numbers.size())
    {
        if (currentValue == target)
        {
            answer++;
        }
        return;
    }

    dfs(numbers, target, index + 1, currentValue + numbers[index]);
    dfs(numbers, target, index + 1, currentValue + (numbers[index] * -1));

    return;
}


int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}