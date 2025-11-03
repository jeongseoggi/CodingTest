#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;


bool isPrime(long long value)
{
    if (value <= 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(value); ++i)
    {
        if (value % i == 0)
        {
            return false;
        }
    }

    return true;
}


int solution(string numbers) 
{
    int answer = 0;
    set<int> sets;

    sort(numbers.begin(), numbers.end());

    do
    {
        string temp;
        for (int i = 0; i < numbers.size(); ++i)
        {
            temp += numbers[i];

            int value = stoll(temp);
            if (isPrime(value) && sets.find(value) == sets.end())
            {
                answer++;
            }

            sets.insert(stoll(temp));
        }

    } while (next_permutation(numbers.begin(), numbers.end()));

    return answer;
}