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

    public:
        game(int N, int M);
        void dropPiece(int player, int x);
};

#endif