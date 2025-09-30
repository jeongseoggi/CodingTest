#include <string>
#include <vector>

using namespace std;
vector<int> solution(int n, long long left, long long right) 
{
    vector<int> answer;

    for (long long i = left; i <= right; i++)
    {
        //i와 n으로 나눈 몫이 행
        //i와 n으로 나눈 나머지가 열이라고 한다면
        //열이 행보다 작은 경우 -> 행과 열이 같아질 때 까지 해당 행의 값을 넣어준다.
        //행이 열보다 작은 경우 -> 현재 행 + (열 - 행) 의 값을 넣어준다.


        int row = i / n; 
        int added = i % n;
        int value = 0; 
       
        if (row >= added)
        {
            value = row + 1;
        }
        else
        {
            value = (row + 1) + (added - row);
        }
        answer.push_back(value);
    }

    return answer;
}