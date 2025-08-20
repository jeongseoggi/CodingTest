using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;

    long long totalprice = 0;
    for(int i = 1; i <= count; i++)
    {
        totalprice += price * i;
    }
    
    answer = totalprice > money ? totalprice - money : 0;
    
    return answer;
}