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

    for (int row = size - 1; row > 0; row--) //y value
    {
        // |   |   |   | row of columns
        cout << "|";
        for (int column = 0; column <= size-1; column++) //x value
        {
            cout << board[column][row];
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
        cout << board[column][0];
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