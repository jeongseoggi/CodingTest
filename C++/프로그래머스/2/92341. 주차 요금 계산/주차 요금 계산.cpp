#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

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
                int carIntime;
                int carOuttime;

                if (i >= out.size())
                {
                    string carInhourStr, carInMinStr;
                    stringstream ss(v[i]);
                    getline(ss, carInhourStr, ':');
                    ss >> carInMinStr;

                    carIntime = (stoi(carInhourStr) * 60) + stoi(carInMinStr);
                    finalTime += maxTime - carIntime;
                }
                else
                {
                    string carInhourStr, carInMinStr;
                    stringstream ss(v[i]);
                    getline(ss, carInhourStr, ':');
                    ss >> carInMinStr;

                    carIntime = (stoi(carInhourStr) * 60) + stoi(carInMinStr);

                    string carOuthourStr, carOutMinStr;
                    stringstream s2(out[i]);
                    getline(s2, carOuthourStr, ':');
                    s2 >> carOutMinStr;

                    carOuttime = (stoi(carOuthourStr) * 60) + stoi(carOutMinStr);

                    finalTime += carOuttime - carIntime;

                }
               
            }
        }
        else
        {
            int carIntime;


            string carInhourStr, carInMinStr;
            stringstream ss(v[0]);
            getline(ss, carInhourStr, ':');
            ss >> carInMinStr;
            carIntime = (stoi(carInhourStr) * 60) + stoi(carInMinStr);
            finalTime = maxTime - carIntime;
        }
        
        if (finalTime <= fees[0])
        {
            price += fees[1];
        }
        else
        {


            int test = ceil((finalTime - fees[0]) / static_cast<double>(fees[2]));

            price += fees[1] + ceil((finalTime - fees[0]) / static_cast<double>(fees[2])) * fees[3];
        }


        answer.push_back(price);
    }

    return answer;
}