#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;

    sort(people.begin(), people.end()); // 무게 순 정렬

    int start = 0;
    int end = people.size() - 1;

    // 투 포인터
    while (start <= end)
    {
        if (people[start] + people[end] <= limit) // 두 무게가 limit가 넘지 않는 경우 두 사람 보트에 탑승
        {
            start++;
            end--;
        }
        else
        {
            end--;
        }

        answer++;
    }

    return answer;
}
