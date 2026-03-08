#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>

using namespace std;

class game
{
    private:
        int size = 0; //N: NxN size of grid
        int winState; //M: how many in a row to win
        vector<vector<char>> board;
        bool checkDirection(int row, int col, int dRow, int dCol, char piece);

    public:
        game(int N, int M);
        vector<vector<char>> getBoard();
        void dropPiece(int player, int x);
        bool checkDraw();
        bool checkWin(char piece);

};

#endif