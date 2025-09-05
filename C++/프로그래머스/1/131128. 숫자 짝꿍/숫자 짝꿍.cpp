#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(string X, string Y)
{
    string answer = "";

    map<int, int> mapsX;
    map<int, int> mapsY;

    for (int i = 0; i < 10; i++)
    {
        mapsX.insert(make_pair(i, 0));
        mapsY.insert(make_pair(i, 0));
    }


    for (int i = 0; i < X.size(); i++)
    {
        string s(1, X[i]);
        int val = stoi(s);

        mapsX[val]++;
    }

    for (int i = 0; i < Y.size(); i++)
    {
        string s(1, Y[i]);
        int val = stoi(s);
        mapsY[val]++;
    }

    for (int i = 9; i >= -1; i--)
    {

        if (mapsX[i] == 0 && mapsY[i] == 0)
        {
            continue;
        }
        else
        {
            int value = mapsX[i] > mapsY[i] ? mapsY[i] : mapsX[i];
            for (int j = 0; j < value; j++)
                answer += to_string(i);
        }
    }

    if (answer.empty())
    {
        answer = "-1";
    }
    else if (answer[0] == '0')
    {
        answer = "0";
    }

    return answer;
}
