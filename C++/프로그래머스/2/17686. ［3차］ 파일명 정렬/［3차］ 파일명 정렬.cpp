#include <bits/stdc++.h>

using namespace std;

string toLower(const string& str)
{
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);

    return result;
}


vector<string> solution(vector<string> files) 
{
    vector<string> answer;

    vector<vector<string>> v;

    for (string file : files)
    {
        string head = "", num = "", tail = "";
        int index = 0;
        int len = file.size();

        while (index < len && !isdigit(file[index]))
        {
            head += file[index++];
        }

        while (index < len && isdigit(file[index]) && num.size() < 5)
        {
            num += file[index++];
        }

        tail = file.substr(index);

        v.push_back({ head, num, tail });
    }

    stable_sort(v.begin(), v.end(), [](const vector<string>& a, const vector<string>& b)
        {
            if (toLower(a[0]) == toLower(b[0]))
                return stoi(a[1]) < stoi(b[1]);

            return toLower(a[0]) < toLower(b[0]);
        });

    for (vector<string> str : v)
    {
        answer.push_back(str[0] + str[1] + str[2]);
    }


    return answer;
}