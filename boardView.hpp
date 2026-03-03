#ifndef BOARDVIEW_HPP
#define BOARDVIEW_HPP

#include <iostream>
#include <vector>

using namespace std;

class boardView
{
    private:
        int size = 0; //N: rows/cols

    public:
        boardView(int N);
        void showBoard(vector<vector<char>> board);
};

#endif