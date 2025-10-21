#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    vector<int> dp(y + 1, -1);
    dp[x] = 0; // 시작점은 0회

    for (int i = x; i <= y; i++) {
        if (dp[i] == -1) continue; // 아직 도달 불가능한 값은 패스

        if (i + n <= y) {
            if (dp[i + n] == -1) dp[i + n] = dp[i] + 1;
            else dp[i + n] = min(dp[i + n], dp[i] + 1);
        }

        if (i * 2 <= y) {
            if (dp[i * 2] == -1) dp[i * 2] = dp[i] + 1;
            else dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        }

        if (i * 3 <= y) {
            if (dp[i * 3] == -1) dp[i * 3] = dp[i] + 1;
            else dp[i * 3] = min(dp[i * 3], dp[i] + 1);
        }
    }

    return dp[y];
}