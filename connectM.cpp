#include <iostream>
#include <string>

#include "boardView.hpp"
#include "game.hpp"

using namespace std;

//connectM N M H
//N: rows/cols in NxN grid
//M: how many connected to win
//H: human or computer first move (1 or 0)

//arg c argument
//argv is a list of args passedfrom the command line
int main(int argc, char* argv[])
{
    bool playerTurn = false;
    int choice;
    const int human = 1;
    const int computer = 0;

    if (argc != 4) //make sure only 4 arguments
    {
        cerr << "Usage: " << argv[0] << " <N> <M> <H>" << endl;
        return 1;
    }

    //args
    int N = stoi(argv[1]); //rows/cols in NxN grid
    int M = stoi(argv[2]); //how many connected to win
    int H = stoi(argv[3]); //0 or 1

    boardView view = boardView(N);
    game myGame = game(N, M);
    view.showBoard();

    cout << "Welcome to Connect M!" << endl;
    if (H = 1)
    {
        playerTurn = true;
    }

    while (true)
    {
        if (playerTurn == true) //player turn
        {
            cout << "which column do you want to drop at? Type -1 to exit" << endl;
            cin >> choice;

            if (choice == -1) //check for exit
            {
                cout << "Exiting program..." << endl;
                return 0;
            }
            while (choice > N || choice <= 0) //invalid input
            {
                cout << "Please enter a valid row (1-" << N << "). Type -1 to exit" << endl;
                cin >> choice;
                
                if (choice == -1) //check for exit
                {
                    cout << "Exiting program..." << endl;
                    return 0;
                }
            }
            cout << "players's turn..." << endl;
            //myGame.dropPiece(human, choice);
            //  FIXME:
            //if win/tie condition, break out of loop
            playerTurn = false;
        }
        else //computer turn
        {
            //  FIXME:
            //ai logic goes here
            //choice = findMove()
            //myGame.dropPiece(computer, choice);
            cout << "computer's turn..." << endl;
            //  FIXME:
            //if win/tie condition, break out of loop
            playerTurn = true;
        }
    }

    return 0;
}