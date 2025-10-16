#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int TimeCalculate(string timeStr)
{
    string hourStr, minStr;
    stringstream ss(timeStr);
    getline(ss, hourStr, ':');
    ss >> minStr;

    return (stoi(hourStr) * 60) + stoi(minStr);
}


vector<int> solution(vector<int> fees, vector<string> records) 
{
    vector<int> answer;

    map<string, vector<string>> carInMap;
    map<string, vector<string>> carOutMap;

    int maxTime = 1439;


    for (int i = 0; i < records.size(); i++)
    {
        string x, y, z;
        stringstream ss(records[i]);
        ss >> x >> y >> z;

        if (z == "IN")
        {
            carInMap[y].push_back(x);
        }
        else
        {
            carOutMap[y].push_back(x);
        }
    }

    
    for (auto it = carInMap.begin(); it != carInMap.end(); ++it)
    {
        vector<string> v = it->second;

        int price = 0;
        int finalTime = 0;
        if (carOutMap.find(it->first) != carOutMap.end())
        {
            vector<string> out = carOutMap[it->first];

            for (int i = 0; i < v.size(); ++i)
            {
                if (i >= out.size())
                {      
                    finalTime += maxTime - TimeCalculate(v[i]);
                }
                else
                {
                    finalTime += TimeCalculate(out[i]) - TimeCalculate(v[i]);
                }
            }
        }
        else
        {
            finalTime = maxTime - TimeCalculate(v[0]);
        }
        
        if (finalTime <= fees[0])
        {
            price += fees[1];
        }
        else
        {
            price += fees[1] + ceil((finalTime - fees[0]) / static_cast<double>(fees[2])) * fees[3];
        }
        answer.push_back(price);
    }

    return answer;
}
