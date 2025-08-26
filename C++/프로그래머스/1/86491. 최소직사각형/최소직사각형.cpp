#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const int& a, const int& b)
{
	return a > b;
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;

	vector<int> v;



	for (int i = 0; i < sizes.size(); i++)
	{
		for (int j = 0; j < sizes[i].size(); j++)
		{
			v.push_back(sizes[i][j]);
		}
	}

	sort(v.begin(), v.end(), compare);

	int w = v[0];
	int h = v[v.size() - 1];
	int num = 1;

	for (int i = 0; i < sizes.size(); i++)
	{
		if (sizes[i][1] > h)
		{
			if (sizes[i][0] > h)
			{
				num++;
				h = v[v.size() - num];
				i--;
			}
		}
	}

	answer = w * h;

    return answer;
}