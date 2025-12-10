#include <bits/stdc++.h>
using namespace std;


vector<int> solution(vector<int> answers)
{
	vector<int> v;

	vector<int> first = { 1,2,3,4,5 };
	vector<int> second = { 2,1,2,3,2,4,2,5 };
	vector<int> third = { 3,3,1,1,2,2,4,4,5,5 };

	map<int, int> correctMap;

	for (int i = 0; i < answers.size(); ++i)
	{
		int firstNum = first[i % first.size()];
		int secondNum = second[i % second.size()];
		int thirdNum = third[i % third.size()];

		if (firstNum == answers[i])
		{
			correctMap[1]++;
		}
		if (secondNum == answers[i])
		{
			correctMap[2]++;
		}
		if (thirdNum == answers[i])
		{
			correctMap[3]++;
		}
	}

	int maxCorrect = 0;

	for (auto it = correctMap.begin(); it != correctMap.end(); ++it)
	{
		if (it->second > maxCorrect)
		{
			maxCorrect = it->second;
		}
	}

	for (auto it = correctMap.begin(); it != correctMap.end(); ++it)
	{
		if (maxCorrect == it->second)
		{
			v.push_back(it->first);
		}
	}

	return v;
}