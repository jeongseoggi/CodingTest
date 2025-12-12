#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) 
{
    int answer = 0;
     
    bool FlagA = false;
    bool FlagB = false;

    if (arrayA.size() == 1)
    {
        if (arrayA[0] == arrayB[0])
        {
            return answer;
        }

        return max(arrayA[0], arrayB[0]);
    }

    int GCD_A = arrayA[0];
    int GCD_B = arrayB[0];

    for (int i = 0; i < arrayA.size(); ++i)
    {
        GCD_A = GCD(arrayA[i], GCD_A);
        GCD_B = GCD(arrayB[i], GCD_B);
    }

    if (GCD_A == 1 && GCD_B == 1)
    {
        return answer;
    }

    for (int i = 0; i < arrayA.size(); ++i)
    {
        if (arrayA[i] % GCD_B == 0)
        {
            FlagB = true;
            break;
        }
    }

    for (int i = 0; i < arrayB.size(); ++i)
    {
        if (arrayB[i] % GCD_A == 0)
        {
            FlagA = true;
            break;
        }
    }

    if (!FlagA && !FlagB)
    {
        answer = max(GCD_A, GCD_B);
    }
    else if (!FlagA && FlagB)
    {
        answer = GCD_A;
    }
    else if (FlagA && !FlagB)
    {
        answer = GCD_B;
    }


    return answer;
}