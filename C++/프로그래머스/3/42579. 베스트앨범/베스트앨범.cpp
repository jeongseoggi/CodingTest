#include <bits/stdc++.h>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	unordered_map<string, vector<pair<int, int>>> albumMaps;
	map<string, int> countMap;

	for (int i = 0; i < genres.size(); ++i)
	{
		if (albumMaps[genres[i]].size() == 0)
		{
			vector<pair<int, int>> v;
			v.push_back({ i, plays[i] });

			albumMaps[genres[i]] = v;
		}
		else
		{
			albumMaps[genres[i]].push_back({ i, plays[i] });
		}
		countMap[genres[i]] += plays[i];
	}

	vector<pair<string, int>> vec(countMap.begin(), countMap.end());

	sort(vec.begin(), vec.end(), [](pair<string, int> a, pair<string, int> b) {
		return a.second > b.second;
		});

	for (auto it = albumMaps.begin(); it != albumMaps.end(); ++it)
	{
		vector<pair<int, int>> temp(it->second.begin(), it->second.end());
		sort(temp.begin(), temp.end(), Compare);

		albumMaps[it->first] = temp;
	}





	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		auto findMap = albumMaps[it->first];
		int count = 2;
		for (auto it = findMap.begin(); it != findMap.end(); ++it)
		{
			if (count == 0)
			{
				break;
			}

			answer.push_back(it->first);
			--count;
		}
	}

	return answer;
}

