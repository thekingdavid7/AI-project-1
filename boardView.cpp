#include "boardView.hpp"

boardView::boardView(int N)
{
    size = N;
}

void boardView::showBoard(vector<vector<char>> board)
{   
    // ------------- top line
    cout << "------";
    for (int i = 1; i < size; i++)
    {
        cout << "-----";
    }
    cout << endl;

    for (int row = 0; row < size - 1; row++) //y value
    {
        // |   |   |   | row of columns
        cout << "|";
        for (int column = 0; column <= size-1; column++) //x value
        {
            cout << board[row][column];
            cout << "   |";
        }
        cout << endl;

        // |---+---+---| finish row
        cout << "|";
        for (int j = 0; j < size-1; j++)
        {
            cout << "----+";
        }
        cout << "----|";
        cout << endl;
    }

    cout << "|"; // |   |   |   |
    for (int column = 0; column <= size - 1; column++)
    {
        cout << board[size - 1][column];
        cout << "   |";
    }
    cout << endl;
    cout << "------"; // -------------
    for (int i = 1; i < size; i++) //bottom line
    {
        cout << "-----";
    }
    cout << endl;
    
    // -------------
    // |   |   |   |
    // |---+---+---|
    // |   |   |   |
    // |---+---+---|
    // |   |   |   |
    // |---+---+---|
    // |   |   |   |
    // -------------
}