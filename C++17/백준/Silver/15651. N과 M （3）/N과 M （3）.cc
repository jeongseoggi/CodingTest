#include <bits/stdc++.h>

using namespace std;

int N;
int M;
vector<int> numbers;

void backTrack(vector<bool>& used, vector<int>& Permutation)
{

	if (Permutation.size() == M)
	{
		for (int i = 0; i < Permutation.size(); ++i)
		{
			cout << Permutation[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (!used[i] || Permutation.size() != N)
		{
			used[i] = true;
			Permutation.push_back(numbers[i]);
			backTrack(used, Permutation);
			used[i] = false;
			Permutation.pop_back();
		}
	}
}


int main()
{
	cin >> N >> M;

	numbers.resize(N);
	for (int i = 0; i < N; ++i)
	{
		numbers[i] = i + 1;
	}

	vector<bool> used(N, false);

	vector<int> Permutation;
	backTrack(used, Permutation);

	return 0;
}
