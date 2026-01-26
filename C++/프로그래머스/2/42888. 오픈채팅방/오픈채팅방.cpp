#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) 
{
    vector<string> answer;

    
    unordered_map<string, string> users;
    unordered_map<string, queue<string>> maps;
    queue<string> q;


    for (string s : record)
    {
        stringstream ss(s);
        string x, y, z;

        ss >> x >> y >> z;

        if (x == "Enter" || x == "Change")
        {
            users[y] = z;
        }

        maps[x].push(y);
        q.push(x);
    }

    while (!q.empty())
    {
        string str = q.front();
        q.pop();


        string str2 = maps[str].front();
        maps[str].pop();


        if (str == "Enter")
        {
            answer.push_back(users[str2] + "님이 들어왔습니다.");
        }
        else if (str == "Leave")
        {
            answer.push_back(users[str2] + "님이 나갔습니다.");
        }
    }

    return answer;
}