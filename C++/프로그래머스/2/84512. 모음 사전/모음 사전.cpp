#include <bits/stdc++.h>

using namespace std;

int solution(string word)
{
	int answer = 0;
	vector<int> v = { 781, 156, 31, 6, 1 };
	map<char, int> wordMaps;

	wordMaps['A'] = 0;
	wordMaps['E'] = 1;
	wordMaps['I'] = 2;
	wordMaps['O'] = 3;
	wordMaps['U'] = 4;

	for (int i = 0; i < word.size(); ++i)
	{
		answer += (wordMaps[word[i]] * v[i]) + 1;
	}

	return answer;
}
