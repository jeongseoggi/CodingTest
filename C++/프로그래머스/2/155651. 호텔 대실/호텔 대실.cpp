#include <string>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
using namespace std;


int ConvertTime(string time)
{
    stringstream ss(time);
    string timeStr;
    vector<string> vec;

    while (getline(ss, timeStr, ':'))
    {
        vec.push_back(timeStr);
    }

    return stoi(vec[0]) * 60 + stoi(vec[1]);
}

int solution(vector<vector<string>> book_time) 
{
    int answer = 0;

    multimap<int ,int> bookMaps;

    for (int i = 0; i < book_time.size(); ++i)
    {
        bookMaps.insert(make_pair(ConvertTime(book_time[i][0]), ConvertTime(book_time[i][1])));
    }

    priority_queue<int, vector<int>, greater<int>> pq;


    for (auto& book : bookMaps)
    {
        if (!pq.empty() && pq.top() + 10 <= book.first)
        {
            pq.pop();
        }
        pq.push(book.second);
    }

    return pq.size();
}
