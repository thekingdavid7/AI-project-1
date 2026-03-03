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
    
}