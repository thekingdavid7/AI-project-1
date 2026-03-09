#include "game.hpp"

game::game(int N, int M)
{
    this->size = N;
    this->winState = M;
    this->board = vector<vector<char>>(N, vector<char>(N, ' '));
}

vector<vector<char>> game::getBoard()
{
    return this->board;
}

void game::dropPiece(int player, int x)
{
    int col = x - 1;
    char piece;

    if (player == 1)
    {
        piece = 'X';
    }

    else
    {
        piece = 'O';
    }

    for (int row = size - 1; row >= 0; row--)
    {
        if (board[row][col] == ' ')
        {
            board[row][col] = piece;
            return;
        }
    }
}

bool game::checkWin(char piece)
{
    int directions [4][2] = {{0,1}, {1,0}, {1,1}, {1,-1}};
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++) 
        {
            for (int dirIndex = 0; dirIndex < 4; dirIndex++)
            {
                if (checkDirection(row, col, directions[dirIndex][0], directions[dirIndex][1], piece))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool game::checkDraw()
{
    for (int col = 0; col < size; col++)
    {
        if (board[0][col] == ' ')
        {
            return false;
        }
    }
    return true;
}

bool game::checkDirection(int row, int col, int dRow, int dCol, char piece)
{
    for (int i = 0; i < winState; i++)
    {
        int r = row + i * dRow;
        int c = col + i * dCol;

        if (r < 0 || r >= size || c < 0 || c >= size)
        {
            return false;
        }

        if (board[r][c] != piece)
        {
            return false;
        }
    }

    return true;
}

int game::getSize()
{
    return size;
}

int game::getWinState()
{
    return winState;
}