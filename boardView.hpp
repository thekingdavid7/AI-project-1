#ifndef BOARDVIEW_HPP
#define BOARDVIEW_HPP

#include <iostream>

using namespace std;

class boardView
{
    private:
        int size = 0; //N: rows/cols

    public:
        boardView(int N);
        void showBoard();
};

#endif