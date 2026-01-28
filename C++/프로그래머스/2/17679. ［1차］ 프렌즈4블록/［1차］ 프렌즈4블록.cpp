#include <bits/stdc++.h>

using namespace std;

void UpdateBoard(vector<string>& Board, vector<vector<bool>>& IsDeleted, int SizeX, int SizeY)
{
    for (int CurrentY = SizeY - 1; CurrentY >= 0; --CurrentY)
    {
        for (int CurrentX = 0; CurrentX < SizeX; ++CurrentX)
        {
            if (IsDeleted[CurrentY][CurrentX])
            {
                int NextPosY = CurrentY - 1;

                while (true)
                {
                    if (NextPosY < 0)
                    {
                        break;
                    }
                    else if (!IsDeleted[NextPosY][CurrentX])
                    {
                        Board[CurrentY][CurrentX] = Board[NextPosY][CurrentX];
                        IsDeleted[NextPosY][CurrentX] = true;
                        IsDeleted[CurrentY][CurrentX] = false;
                        Board[NextPosY][CurrentX] = 'X';

                        break;
                    }

                    Board[NextPosY][CurrentX] = 'X';
                    NextPosY -= 1;
                }
            }
        }
    }
}



int solution(int m, int n, vector<string> board)
{
    int answer = 0;

    bool isEnd = true;

    int xSize = board[0].size();
    int ySize = board.size();

    vector<vector<bool>> deleted(ySize, vector<bool>(xSize, false));
    vector<vector<bool>> counted(ySize, vector<bool>(xSize, false));


    while (true)
    {
        for (int curY = 0; curY < ySize - 1; ++curY)
        {
            for (int curX = 0; curX < xSize - 1; ++curX)
            {
                char curChar = board[curY][curX];

                if (curChar == 'X')
                {
                    continue;
                }

                if (board[curY + 1][curX + 1] == curChar && board[curY + 1][curX] == curChar &&
                    board[curY][curX + 1] == curChar)
                {
                    isEnd = false;

                    if (!deleted[curY + 1][curX + 1])
                    {
                        answer += 1;
                        deleted[curY + 1][curX + 1] = true;
                    }

                    if (!deleted[curY + 1][curX])
                    {
                        answer += 1;
                        deleted[curY + 1][curX] = true;
                    }

                    if (!deleted[curY][curX + 1])
                    {
                        answer += 1;
                        deleted[curY][curX + 1] = true;
                    }
                    if (!deleted[curY][curX])
                    {
                        answer += 1;
                        deleted[curY][curX] = true;
                    }
                }
            }
        }

        if (isEnd)
        {
            break;
        }
        else
        {
            isEnd = true;
            UpdateBoard(board, deleted, xSize, ySize);
        }
    }

    return answer;
}