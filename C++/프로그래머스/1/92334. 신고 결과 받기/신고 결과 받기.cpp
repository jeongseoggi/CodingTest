#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer(id_list.size(), 0);
    unordered_map<string, set<string>> report_map;
    unordered_map<string, int> maps;

    for (int i = 0; i < id_list.size(); i++)
    {
        maps[id_list[i]] = i;
    }

    string user;
    string reportUser;


    for (int i = 0; i < report.size(); i++)
    {
        stringstream ss(report[i]);
        ss >> user >> reportUser;

        report_map[reportUser].insert(user);
    }



    for (auto it = report_map.begin(); it != report_map.end(); it++)
    {
        if (it->second.size() >= k) //이 아이디를 신고한 유저들이 2명 이상일 경우
        {
            for (auto setit = it->second.begin(); setit != it->second.end(); setit++)
            {
                answer[maps[*setit]]++;
            }
        }
    }



    return answer;
}