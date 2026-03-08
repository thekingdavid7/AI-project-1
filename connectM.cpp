#include <iostream>
#include <string>

#include "boardView.hpp"
#include "game.hpp"
#include "aiLogic.hpp"

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
    int aiChoice;
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
    // Fill in once constructor is designed.
    // aiLogic ai = 
    view.showBoard(myGame.getBoard());

    cout << "Welcome to Connect M!" << endl;
    if (H == 1)
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
            view.showBoard(myGame.getBoard());
            cout << "players's turn..." << endl;
            myGame.dropPiece(human, choice);
            view.showBoard(myGame.getBoard());
            
            if (myGame.checkWin('X'))
            {
                cout << "You Win!" << endl;
                break;
            }

            if (myGame.checkDraw())
            {
                cout << "Draw!" << endl;
                break;
            }
            playerTurn = false;
        }
        else //computer turn
        {
            aiChoice = ai.choice(game);
            myGame.dropPiece(computer, aiChoice);
            view.showBoard(myGame.getBoard());
            cout << "computer's turn..." << endl;

            if (myGame.checkWin('O'))
            {
                cout << "Computer Wins!" << endl;
                break;
            }

            if (myGame.checkDraw())
            {
                cout << "Draw!" << endl;
                break;
            }
            playerTurn = true;
        }
    }

    return 0;
}