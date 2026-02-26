#include <bits/stdc++.h>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    int next = n + 1;


    bitset<10> nBit(n);

    while (true)
    {
        bitset<10> nextBit(next);

        if (nextBit.count() == nBit.count())
        {
            break;
        }

        next++;
    }

    answer = next;

    return answer;
}