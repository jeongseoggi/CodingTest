//다시 푸셈

#include <string>
#include <vector>

using namespace std;

int Dungeon(int count, int power, vector<vector<int>> dungeons, vector<bool> visited)
{
	int maxCount = count;

	for (int i = 0; i < dungeons.size(); ++i)
	{
		if (visited[i] || power < dungeons[i][0])
		{
			continue;
		}

		visited[i] = true;
		maxCount = max(Dungeon(count + 1, power - dungeons[i][1], dungeons, visited), maxCount);
		visited[i] = false;
	}

	return maxCount;
}

int solution(int k, vector<vector<int>> dungeons)
{
	vector<bool> visited(dungeons.size(), false);
	return Dungeon(0, k, dungeons, visited);
}
