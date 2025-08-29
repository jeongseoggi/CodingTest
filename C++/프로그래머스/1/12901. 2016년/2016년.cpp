#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(int a, int b)
{
    string answer = "";
    map<int, string> map;

    int year = 2016;


    // 1월은 13월 2월은 14월로 계산
    if (a == 1 || a== 2)
    {
        year -= 1;
        a = a == 1 ? 13 : 14;
    }

    map.insert(make_pair(0, "SAT"));
    map.insert(make_pair(1, "SUN"));
    map.insert(make_pair(2, "MON"));
    map.insert(make_pair(3, "TUE"));
    map.insert(make_pair(4, "WED"));
    map.insert(make_pair(5, "THU"));
    map.insert(make_pair(6, "FRI"));


    // Zeller 공식
    int K = year % 2000;
    int J = year / 100;

    // Zeller 공식 계산
    int h = (b + (13 * (a + 1)) / 5 + K + K / 4 + J / 4 - 2 * J) % 7;

    if(h < 0)
    {
        h += 7;
    }
    answer = map[h];

    return answer;
}