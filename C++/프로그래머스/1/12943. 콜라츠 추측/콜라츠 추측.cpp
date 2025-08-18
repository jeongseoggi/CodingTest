#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    while(true)
    {
        if(answer > 500)
        {
            answer = -1;
            break;
        }
        else if(num == 1)
        {
            break;
        }
        else if(num == 0)
        {
            answer = 0;
            break;
        }
        else if (num < 0)
        {
          answer = -1;
          break;
        }
          
        num = num % 2 == 0 ? num / 2 : num * 3 + 1;
        answer++;
            
    }
    
    
    return answer;
}