#include <iostream>
#include <string>

#include "boardView.hpp"

using namespace std;

//connectM N M H
//N: rows/cols in NxN grid
//M: how many connected to win
//H: human or computer first move (1 or 0)

//arg c argument
//argv is a list of args passedfrom the command line
int main(int argc, char* argv[])
{
    if (argc != 4) //make sure only 4 arguments
    {
        cerr << "Usage: " << argv[0] << " <N> <M> <H>" << endl;
        return 1;
    }

    //args
    int N = stoi(argv[1]); //rows/cols in NxN grid
    int M = stoi(argv[2]); //how many connected to win
    int H = stoi(argv[3]); //0 or 1
    
    cout << "hello, world!" << endl;
    cout << "N : " << N << endl;
    cout << "M : " << M << endl;
    cout << "H : " << H << endl;

    boardView board = boardView(N);
    board.showBoard();

    return 0;
}