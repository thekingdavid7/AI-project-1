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
        if (!isColPlayable(board, col)) //if column is full, skip
        {
            continue;
        }

        vector<vector<char>> next = board; //copy board
        applyMove(next, col, N, aiToken); //drop a piece in column
        int score = search(next, N, M, maxDepth - 1, numeric_limits<int>::min(), numeric_limits<int>::max(), false); //search resulting board state and get score
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
    //min max algorithm with alpha beta pruning
    if (checkWin(board, N, M, aiToken)) //if ai wins, return high score
    {
        return 1000000 + depth;
    }

    if (checkWin(board, N, M, humanToken)) //if human wins, return low score
    {
        return -1000000 - depth;
    }

    if (isFull(board, N) || depth == 0) //if draw or depth limit reached, return evaluation of board state
    {
        //depth is added to score to prefer faster wins and slower losses
        return evaluate(board, N, M); //the evaluate function will return a score based on how favorable the board state is for the ai, with higher scores being better for the ai and lower scores being better for the human
    }

    if (isMax)
    {
        int best = numeric_limits<int>::min();
        for (int col = 0; col < N; col++)
        {
            if (!isColPlayable(board, col))
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
            if (!isColPlayable(board, col))
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

bool AI::isColPlayable(vector<vector<char>> board, int col)
{
    return board[0][col] == ' ';
}

void AI::applyMove(vector<vector<char>>& board, int col, int N, char piece)
{
    for (int row = N - 1; row >= 0; row--) //start from bottom of column and find first empty space to drop piece
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
                    //these calculations will get the row and column of each piece in the window based on the starting position and direction, and add the piece to the window vector if it is within bounds
                    int r = row + i * directions[dirIndex][0];
                    int c = col + i * directions[dirIndex][1];

                    if (r < 0 || r >= N || c < 0 || c >= N)
                    {
                        break;
                    }

                    window.push_back(board[r][c]); //add piece to window
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
        //the center column is more valuable because it allows for more potential winning combinations, so we will add points for ai pieces in the center column and subtract points for human pieces in the center column
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

//returns score
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
        return 100000; //ai win
    }

    if (oppCount == M)
    {
        return -100000; //human win
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