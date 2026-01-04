#include <bits/stdc++.h>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    int nextValue = n + 1;
    bitset<10> bits(n);

    int count = bits.count();

    while (true)
    {
        bitset<10> bits2(nextValue);

        if (count == bits2.count())
        {
            break;
        }

        nextValue++;
    }

    answer = nextValue;
    return answer;
}
