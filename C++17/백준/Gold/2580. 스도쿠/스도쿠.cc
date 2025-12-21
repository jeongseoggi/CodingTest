#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
vector<pair<int, int>> v;

bool isend = false;

void printBoard()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << board[i][j] << " ";
		}
		
		cout << "\n";
	}
}


bool CheckNum(int targetNumber, int depth, int col)
{
	for (int i = 0; i < 9; ++i) //자기 기준 가로 및 세로 검사
	{
		if (board[depth][i] == targetNumber)
		{
			return false;
		}
		if (board[i][col] == targetNumber)
		{
			return false;
		}
	}
	
	int part_x = depth / 3; // depth == 0 -> 0
	int part_y = col / 3; // col == 0 -> 0
	part_x *= 3; // 0 * 3 == 0
	part_y *= 3; // 0 * 3 == 0
	for (int i = part_x; i < part_x + 3; i++) // 0 ~ 2
	{
		for (int j = part_y; j < part_y + 3; j++)  // 0 ~ 2
		{
			if (board[i][j] == targetNumber)
			{
				return false;
			}
		}
	}


	return true;
}

void Sudoku(unsigned long depth)
{
	//if (depth == v.size()) //0이 들어있는 좌표의 배열의 개수 만큼
	//{
	//	cout << "\n";
	//	printBoard();
	//	return;
	//}


	if (isend == true)
	{
		return;
	}
	if (depth == v.size()) 
	{
		printBoard();
		isend = true;
	}




	int nowRow = v[depth].first; // 현재 줄의 0의 위치
	int nowCol = v[depth].second;

	for (int i = 1; i <= 9; ++i)
	{
		if (CheckNum(i, nowRow, nowCol))
		{
			board[nowRow][nowCol] = i;
			Sudoku(depth + 1);
			board[nowRow][nowCol] = 0;
		}
	}
}

int main()
{
	board.resize(9, vector<int>(9, 0));

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
			{
				v.push_back({ i ,j });
			}
		}
	}

	Sudoku(0);

	return 0;

}