#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;

    int n = land.size();
    vector<vector<int>> dp = land;

    for (int i = 1; i < n; ++i) 
    {
        dp[i][0] += max({ dp[i - 1][1], dp[i - 1][2], dp[i - 1][3] }); // 현재 선택한 열 0번 0번을 제외한 나머지 중 가장 큰 값을 더해서 저장 (i == 0 -> 5 += {2, 3, 5} -> 5 + 5 = 10)
        dp[i][1] += max({ dp[i - 1][0], dp[i - 1][2], dp[i - 1][3] }); // 현재 선택한 열 1번 1번을 제외한 나머지 중 가장 큰 값을 더해서 저장 (i == 1 -> 6 += {1, 3, 5} -> 6 + 5 = 11)
        dp[i][2] += max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][3] }); // 현재 선택한 열 2번 2번을 제외한 나머지 중 가장 큰 값을 더해서 저장 (i == 2 -> 7 += {1, 2, 5} -> 7 + 5 = 12)
        dp[i][3] += max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] }); // 현재 선택한 열 3번 3번을 제외한 나머지 중 가장 큰 값을 더해서 저장 (i == 3 -> 8 += {1, 2, 3} -> 8 + 3 = 11)
    }

    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}