#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    //재배열 부등식 : 큰 값은 작은 값과 곱해야 전체 합이 최소
    //따라서 A는 오름차순 정렬, B는 내림 차순 정렬하여, A의 첫번째 요소는 가장 작은 값, B의 첫번째 요소는 가장 큰 값으로 재배열 부등식 성립
    sort(A.begin(), A.end()); // 오름 차순
    sort(B.begin(), B.end(), greater<int>());  //내림차순

    for (int i = 0; i < A.size(); ++i)
    {
        answer += A[i] * B[i];
    }

    return answer;
}