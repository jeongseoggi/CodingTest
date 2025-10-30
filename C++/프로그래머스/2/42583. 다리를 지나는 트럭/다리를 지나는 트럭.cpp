#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0;
    int time = 1;
    int totalWeight = 0;
    int truckCount = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < truck_weights.size(); ++i)
    {
        if (bridge_length == truckCount || totalWeight + truck_weights[i] > weight)
        {
            pair<int, int> truck = q.front();
            q.pop();

            totalWeight -= truck.first;
            truckCount -= 1;

            if (time < truck.second + bridge_length)
            {
                time = truck.second + bridge_length;
            }
            i--;
        }
        else
        {
            q.push({ truck_weights[i], time });
            totalWeight += truck_weights[i];
            truckCount += 1;
            time++;
        }
    }

    while (!q.empty())
    {
        pair<int, int> truck = q.front();
        time = truck.second + bridge_length;
        q.pop();
    }

    answer = time;

    return answer;
}