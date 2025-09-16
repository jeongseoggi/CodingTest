#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> splitString(string s)
{
    istringstream ss(s);
    string temp;
    vector<string> v;

    while (getline(ss, temp, '.'))
    {
        v.push_back(temp);
    }

    return v;
}


vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    vector<int> answer;
    map<char, int> maps;
    vector<string> v2 = splitString(today);

    int todayYear = stoi(v2[0]);
    int todayMonth = stoi(v2[1]);;
    int todayDate = stoi(v2[2]);;



    for (int i = 0; i < terms.size(); i++)
    {
        string mon;
        for (int j = 2; j < terms[i].size(); j++)
        {
            mon += terms[i][j];
        }
        maps.insert(make_pair(terms[i][0], stoi(mon)));
    }

    for (int i = 0; i < privacies.size(); i++)
    {
        vector<string> v1 = splitString(privacies[i]);

        int year = stoi(v1[0]);
        int month = stoi(v1[1]);
        int day = stoi(v1[2]);
        int terms = maps[privacies[i][privacies[i].size() - 1]];

        
        int addTerm = month + terms;

        if (addTerm > 12)
        {
            year += terms / 12;
            month += terms % 12;
            if (month > 12)
            {
                year++;
                month -= 12;
            }
        }
        else
        {
            month += terms;
        }
        
        if (day - 1 <= 0)
        {
            day = 28;
            month--;

            if (month <= 0)
            {
                year -= 1;
                month = 12;
            }
        }
        else
        {
            day--;
        }

        if ((year * (12 * 28)) + (month * 28) + day < (todayYear * (12 * 28)) + (todayMonth * 28) + todayDate)
        {
            answer.push_back(i + 1);
        }
    }
    return answer;
}
