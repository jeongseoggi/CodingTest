#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int M;
	cin >> N >> M;
	cin.ignore();

	map<string, string> passMap;

	for (int i = 0; i < N; ++i)
	{
		string s;
		getline(cin, s);
		
		stringstream ss(s);

		string site;
		string pw;

		ss >> site >> pw;

		passMap[site] = pw;
	}
	
	vector<string> v;
	for (int i = 0; i < M; ++i)
	{
		string site;
		cin >> site;

		v.push_back(passMap[site]);
	}

	for (const string& str : v)
	{
		cout << str << endl;
	}
	return 0;
}