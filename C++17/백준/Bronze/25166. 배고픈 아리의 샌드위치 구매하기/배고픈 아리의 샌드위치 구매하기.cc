#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int S;
	int M;
	cin >> S >> M;
	cin.ignore();

	const int AHRI_NUM = (1 << 10) - 1;

	if (S <= AHRI_NUM)
	{
		cout << "No thanks\n";
		return 0;
	}

	int need = S - AHRI_NUM;

	if (need > M)
	{
		cout << "Impossible";
		return 0;
	}

	if ((need & M) == need)
	{
		cout << "Thanks\n";
	}
	else
	{
		cout << "Impossible\n";
	}



	return 0;
}