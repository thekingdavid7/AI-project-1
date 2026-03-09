#include "aiLogic.hpp"
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

AI::AI(int maxDepth)
{
    this->maxDepth = maxDepth;
}

int AI::choice(game& currentState, char humanToken, char aiToken)
{
    this->humanToken = humanToken;
    this->aiToken = aiToken;

    vector<vector<char>> board = currentState.getBoard();
    int N = currentState.getSize();
    int M = currentState.getWinState();
    int bestScore = numeric_limits<int>::min();
    int bestCol = -1;

    for (int col = 0; col < N; col++)
    {
        if (!isColPlayable(board, col, N))
        {
            continue;
        }

        vector<vector<char>> next = board;
        applyMove(next, col, N, aiToken);
        int score = search(next, N, M, maxDepth - 1, numeric_limits<int>::min(), numeric_limits<int>::max(), false);
        if (score > bestScore)
        {
            bestScore = score;
            bestCol = col;
        }
    }
    return bestCol + 1;
}

int AI::search(vector<vector<char>> board, int N, int M, int depth, int alpha, int beta, bool isMax)
{
    if (checkWin(board, N, M, aiToken))
    {
        return 1000000 + depth;
    }

    if (checkWin(board, N, M, humanToken))
    {
        return -1000000 - depth;
    }

    if (isFull(board, N) || depth == 0)
    {
        return evaluate(board, N, M);
    }

    if (isMax)
    {
        int best = numeric_limits<int>::min();
        for (int col = 0; col < N; col++)
        {
            if (!isColPlayable(board, col, N))
            {
                continue;
            }

            vector<vector<char>> next = board;
            applyMove(next, col, N, aiToken);
            best = max(best, search(next, N, M, depth - 1, alpha, beta, false));
            alpha = max(alpha, best);
            
            if (alpha >= beta)
            {
                break;
            }
        }
        return best;
    }

    else
    {
        int best = numeric_limits<int>::max();

        for (int col = 0; col < N; col++)
        {
            if (!isColPlayable(board, col, N))
            {
                continue;
            }
            vector<vector<char>> next = board;
            applyMove(next, col, N, humanToken);
            best = min(best, search(next, N, M, depth - 1, alpha, beta, true));
            beta = min(beta, best);

            if (alpha >= beta)
            {
                break;
            }
        }
        return best;
    }
}

bool AI::isColPlayable(vector<vector<char>> board, int col, int N)
{
    return board[0][col] == ' ';
}

void AI::applyMove(vector<vector<char>>& board, int col, int N, char piece)
{
    for (int row = N - 1; row >= 0; row--)
    {
        if (board[row][col] == ' ')
        {
            board[row][col] = piece;
            return;
        }
    }
}

bool AI::checkWin(vector<vector<char>> board, int N, int M, char piece)
{
    int directions[4][2] = {{0,1}, {1,0}, {1,1}, {1,-1}};
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            for (int dirIndex = 0; dirIndex < 4; dirIndex++)
            {
                int count = 0;
                for (int i = 0; i < M; i++)
                {
                    int r = row + i * directions[dirIndex][0];
                    int c = col + i * directions[dirIndex][1];

                    if (r < 0 || r >= N || c < 0 || c >= N)
                    {
                        break;
                    }

                    if (board[r][c] != piece)
                    {
                        break;
                    }

                    count++;
                }
                if (count == M)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool AI::isFull(vector<vector<char>> board, int N)
{
    for (int col = 0; col < N; col++)
    {
        if (board[0][col] == ' ')
        {
            return false;
        }
    }
    return true;
}

int AI::evaluate(vector<vector<char>> board, int N, int M)
{
    int total = 0;
    int directions[4][2] = {{0,1}, {1,0}, {1,1}, {1,-1}};

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            for (int dirIndex = 0; dirIndex < 4; dirIndex++)
            {
                vector<char> window;
                for (int i = 0; i < M; i++)
                {
                    int r = row + i * directions[dirIndex][0];
                    int c = col + i * directions[dirIndex][1];

                    if (r < 0 || r >= N || c < 0 || c >= N)
                    {
                        break;
                    }

                    window.push_back(board[r][c]);
                }

                if ((int)window.size() == M)
                {
                    total += scoreWindow(window, M, aiToken);
                }
            }
        }
    }

    int center = N / 2;
    for (int row = 0; row < N; row++)
    {
        if (board[row][center] == aiToken)
        {
            total += 3;
        }

        if (board[row][center] == humanToken)
        {
            total -=3;
        }
    }

    return total;
}

int AI::scoreWindow(vector<char> window, int M, char piece)
{
    int pieceCount = 0;
    int emptyCount = 0;

    for (int i = 0; i < M; i++)
    {
        if (window[i] == piece)
        {
            pieceCount++;
        }
        else if (window[i] == ' ')
        {
            emptyCount++;
        }
    }

    int oppCount = M - pieceCount - emptyCount;

    if (pieceCount == M)
    {
        return 100000;
    }

    if (oppCount == M)
    {
        return -100000;
    }

    if (pieceCount == M - 1 && emptyCount == 1)
    {
        return 50;
    }

    if (pieceCount == M - 2 && emptyCount == 2)
    {
        return 10;
    }

    if (oppCount == M - 1 && emptyCount == 1)
    {
        return -80;
    }

    return 0;
}