#include <bits/stdc++.h>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0)
    {
        int lastDig = storey % 10;
        // lastDigit 값이 5이면 올림/내림 판단 불가로 인해 nextDigit 값을 확인하여 5 이상 -> 올림 / 5미만 -> 내림
        int nextDig = (storey / 10) % 10;
        
        if(lastDig > 5 || (lastDig == 5 && nextDig >= 5))
        {
            storey += 10 - lastDig;
        }
        else
        {
            storey -= lastDig;
        }
        
        storey /= 10;
        
        answer += min(lastDig, 10 - lastDig);
    }
    
    return answer;
}