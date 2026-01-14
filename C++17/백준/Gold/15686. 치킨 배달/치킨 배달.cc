#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

int answer = INT_MAX;

int dist(pair<int, int>& a, pair<int, int>& b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int calcCityDist(vector<int>& selected)
{
    int total = 0;

    for (auto& house : houses)
    {
        int minDist = INT_MAX;

        for (int idx : selected)
        {
            minDist = min(minDist, dist(house, chickens[idx]));
        }

        total += minDist;
    }

    return total;
}

void combination(int start, vector<int>& selected)
{
    if (selected.size() == M)
    {
        answer = min(answer, calcCityDist(selected));
        return;
    }

    for (int i = start; i < chickens.size(); ++i)
    {
        selected.push_back(i);
        combination(i + 1, selected);
        selected.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int chickenCount = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int value = 0;
            cin >> value;
            if (value == 1) 
            {
                houses.push_back({ i, j });
            }
            else if (value == 2)
            {
                chickens.push_back({ i, j });
            }
        }
    }


    vector<int> selected;

    combination(0, selected);

    cout << answer << endl;
    return 0;

}