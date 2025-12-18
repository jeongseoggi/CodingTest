#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> board;
vector<bool> putQueen;
int result;

bool CanPutQueen(int col, int row)
{
	//vector<pair<int, int>> dir = { {-1, 0},{-1, 1},{1, 1},{1, 0},{1, -1},{-1, -1} };
	//bool canPut = true;

	for (int i = 0; i < row; i++) {
		if (board[i][col] == 1) {
			return false;
		}
	}

	// 왼쪽 대각선에 퀸이 있는지 확인
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] == 1) {
			return false;
		}
	}

	// 오른쪽 대각선에 퀸이 있는지 확인
	for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
		if (board[i][j] == 1) {
			return false;
		}
	}

	// 모든 검사를 통과했으므로 유망함!
	return true;
}



void NQueen(int depth)
{
	if (depth == N)
	{
		result++;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (CanPutQueen(i, depth))
		{
			board[depth][i] = 1;
			NQueen(depth + 1);
			board[depth][i] = 0;
		}
	}
}

int main()
{
	cin >> N;

	board.resize(N, vector<int>(N, 0));
	putQueen.resize(N);

	NQueen(0);

	cout << result << "\n";

	return 0;
}