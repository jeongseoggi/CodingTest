#include <string>
#include <vector>

using namespace std;

static int answer = 0;

bool CanPutQueen(vector<vector<int>>& board, int CurRow, int CurCol ,int N)
{
    vector<pair<int, int>> dir = { {0, -1},{0, 1},{-1, 0},{1, 0},{-1, -1},{1, 1},{1, -1},{-1, 1} };
    bool canPut = true;
    for (int i = 0; i < dir.size(); ++i)
    {
        int Row = CurRow;
        int Col = CurCol;

        while (true)
        {
            Row += dir[i].first;
            Col += dir[i].second;

            if (Row < 0 || Col < 0)
            {
                break;
            }

            if (Row >= N || Col >= N)
            {
                break;
            }

            if (board[Row][Col] == 1)
            {
                canPut = false;
                break;
            }
        }

    }

    return canPut;
}


void Queen(vector<vector<int>>& board, int CurRow, int N)
{
    if (CurRow == N)
    {
        answer++;
    }

    for (int i = 0; i < N; ++i)
    {
        if (CanPutQueen(board, CurRow, i, N))
        {
            board[CurRow][i] = 1;
            Queen(board, CurRow + 1, N);

            board[CurRow][i] = 0;
        }
    }
}

int solution(int n) 
{ 
    vector<vector<int>>board(n, vector<int>(n, 0));
    Queen(board, 0, n);

    return answer;
}