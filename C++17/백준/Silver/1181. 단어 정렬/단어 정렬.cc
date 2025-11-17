#include <bits/stdc++.h>

using namespace std;

bool Compare(const string& a, const string& b)
{
	if (a.size() > b.size())
	{
		return false;
	}
	else if (a.size() < b.size())
	{
		return true;
	}
	else
	{
		return a < b;
	}	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	set<string> sets;

	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		sets.insert(s);
	}

	vector<string>v;
	for (const string& str : sets)
	{
		v.push_back(str);
	}
	
	sort(v.begin(), v.end(), Compare);

	for (const string& str : v)
	{
		cout << str << endl;
	}

	return 0;
}