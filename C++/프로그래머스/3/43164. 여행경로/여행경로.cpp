#include <bits/stdc++.h>

using namespace std;

 unordered_map<string, vector<string>> maps;
vector<string> result;

void DFS(string current)
{

	while (!maps[current].empty())
	{
		string next = maps[current].front();
		maps[current].erase(maps[current].begin());
		DFS(next);
	}

	result.push_back(current);
}



vector<string> solution(vector<vector<string>> tickets)
{
	vector<string> answer;

	for (auto& ticket : tickets)
	{
		maps[ticket[0]].push_back(ticket[1]);
	}

	for (auto& [key, destinations] : maps)
	{
		sort(destinations.begin(), destinations.end());
	}

	DFS("ICN");

	reverse(result.begin(), result.end());

	return result;
}