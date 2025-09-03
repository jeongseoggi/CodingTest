#include <string>
#include <vector>
#include <cmath>

using namespace std;

int measureCount(int n)
{
    if (n == 1)
    {
        return 1;
    }

    int count = 2; //1과 n은 항상 포함 
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) //약수를 찾았으면 
        {
            count += 2; // 2더해줌 -> sqrt(n) 때문
            if (i * i == n) //만약에 제곱근인 경우는 제외 ex) 4의 약수 1 ,2, 4 -> n이 4일 때 초기 count = 2 -> sqrt(n) : 2 -> 4 % 2 == 0 :true -> count = 4 -> 2 * 2 == 4 : true -> count 감소 -> 결론 count 3
            {
                count--;
            }
        }
    }
    return count;
}





int solution(int number, int limit, int power) 
{
    int answer = 0;

    for (int i = 1; i <= number; i++)
    {
        int value = measureCount(i);

        if (value > limit)
        {
            value = power;
        }

        answer += value;
    }
    return answer;
}


//원래 제출했던 코드
//효율성이 너무 떨어지는 코드라서 효율성 좋은 코드를 이것저것 찾은 후 다시 작성

// #include <string>
// #include <vector>
// #include <cmath>

// using namespace std;

// int solution(int number, int limit, int power) 
// {
//     int answer = 0;

//     for (int i = 1; i <= number; i++)
//     {
//         int value = i == 1 ? 1 : 2;

//         for (int j = 2; j <= i / 2; j++)
//         {
//             if (i % j == 0)
//             {
//                 value++;
//             }
//         }

//         if (value > limit)
//         {
//             value = power;
//         }
//         answer += value;
//     }

//     return answer;
// }
