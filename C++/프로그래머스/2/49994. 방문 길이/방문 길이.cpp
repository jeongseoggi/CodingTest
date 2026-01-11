#include<bits/stdc++.h>
using namespace std;

int solution(string dirs)
{
    int answer = 0;

    set<tuple<int, int, int, int>> visited;

    int Y = 0;
    int X = 0;



    for (char c : dirs)
    {
        //from
        int nowY = Y;
        int nowX = X;

        if (c == 'U') nowY++;
        if (c == 'D') nowY--;
        if (c == 'R') nowX++;
        if (c == 'L') nowX--;

        if (nowY < -5 || nowY >5 || nowX < -5 || nowX>5)
        {
            continue;
        }

        
        visited.insert({ nowY, nowX, Y, X });
        visited.insert({ Y, X, nowY, nowX });

        Y = nowY;
        X = nowX;
    }


    return visited.size() / 2;
}