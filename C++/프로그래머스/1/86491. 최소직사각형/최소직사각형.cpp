#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) 
{
	int answer = 0;
	vector<int> v;
	for (int i = 0; i < sizes.size(); ++i)
	{
		for (int j = 0; j < sizes[0].size(); ++j)
		{
			v.push_back(sizes[i][j]);
		}
	}

	sort(v.begin(), v.end(), greater<int>());

	int w = v[0];
	int h = v[v.size() - 1];
	int count = 1;


	for (int i = 0; i < sizes.size(); ++i)
	{
		if (sizes[i][1] > h && sizes[i][0] > h)
		{
			count++;
			h = v[v.size() - count];
			i--;
		}
	}

	return w * h;
}