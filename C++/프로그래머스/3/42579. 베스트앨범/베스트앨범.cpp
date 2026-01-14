#include <bits/stdc++.h>

using namespace std;

bool ComparePairint(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

bool ComparePairstring(pair<string,int> a, pair<string,int> b)
{
    return a.second > b.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;

    unordered_map<string, vector<pair<int, int>>> albums;
    unordered_map<string, int> count;

    for (int i = 0; i < genres.size(); ++i)
    {
        albums[genres[i]].push_back({ i,plays[i] });
        count[genres[i]] += plays[i];
    }


   /* vector<pair<string, vector<pair<int, int>>>>v(albums.begin(), albums.end());

    for (int i = 0; i < v.size(); ++i)
    {
        sort(v[i].second.begin(), v[i].second.end(), ComparePairint);
    }*/

    vector<pair<string, int>> countVec(count.begin(), count.end());
    for (int i = 0; i < countVec.size(); ++i)
    {
        sort(countVec.begin(), countVec.end(), ComparePairstring);
    }
    

    for (int i = 0; i < countVec.size(); ++i)
    {
        string temp = countVec[i].first; // "pop"

        vector<pair<int, int>> tempVec = albums[temp];

        for (int j = 0; j < 2; ++j)
        {
            auto it = max_element(tempVec.begin(), tempVec.end(), [](const pair<int, int>& a, const pair<int, int>& b)
                {
                    return a.second < b.second;
                });

            if (it != tempVec.end())
            {
                answer.push_back(it->first);
                tempVec.erase(it);
            }
        }
        
    }
  
    return answer;
}