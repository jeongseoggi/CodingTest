#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, long long k) 
{
    vector<int> answer;
    vector<int> numbers;
    vector<long long> factorial(n);
    
    // 팩토리얼 계산
    factorial[0] = 1;
    for (int i = 1; i < n; i++) 
    {
        factorial[i] = factorial[i-1] * i;
    }
    
    // 사용 가능한 숫자 리스트
    for (int i = 1; i <= n; i++) 
    {
        numbers.push_back(i);
    }
    
    k--; // 0-based index로 변환
    
    // k번째 순열 직접 구성
    for (int i = 0; i < n; i++) 
    {
        int idx = k / factorial[n-1-i];
        answer.push_back(numbers[idx]);
        numbers.erase(numbers.begin() + idx);
        k %= factorial[n-1-i];
    }
    
    return answer;
}