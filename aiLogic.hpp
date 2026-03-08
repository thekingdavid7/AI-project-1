#ifndef AILOGIC_HPP
#define AILOGIC_HPP

#include "game.hpp"
#include <vector>

using namespace std;

class AI
{
    private:
        int maxDepth;
        char humanToken;
        char aiToken;
        bool isColPlayable(vector<vector<char>> board, int col, int N);
        void applyMove(vector<vector<char>>& board, int col, int N, char piece);
        bool checkWin(vector<vector<char>> board, int N, int M, char piece);
        bool isFull(vector<vector<char>> board, int N);
        int scoreWindow(vector<char> window, int M, char piece);
        int evaluate(vector<vector<char>> board, int N, int M);
        int search(vector<vector<char>> board, int N, int M, int depth, int alpha, int beta, bool isMax);

    public:
        AI(int maxDepth);
        int choice(game& currentState, char humanToken, char aiToken);
};
#endif