#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = (int)sequence.size();
    int l = 0, r = 0;
    long long sum = sequence[0];

    int bestL = 0, bestR = n - 1;
    int bestLen = INT_MAX;

    while (l < n && r < n) {
        if (sum < k) {
            r++;
            if (r >= n) break;
            sum += sequence[r];
        } 
        else if (sum > k) {
            sum -= sequence[l];
            l++;
            if (l > r && l < n) {
                r = l;
                sum = sequence[l];
            }
        } 
        else { 
            int len = r - l;
            if (len < bestLen) {          
                bestLen = len;
                bestL = l;
                bestR = r;
            }
          
            sum -= sequence[l];
            l++;
            if (l > r && l < n) {
                r = l;
                sum = sequence[l];
            }
        }
    }

    return {bestL, bestR};
}