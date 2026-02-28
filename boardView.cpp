#include "boardView.hpp"

boardView::boardView(int N)
{
    size = N;
}

void boardView::showBoard()
{   
    cout << "-----"; // -------------
    for (int i = 1; i < size; i++) //top line
    {
        cout << "----";
    }

    cout << endl;

    for (int i = 1; i <= size - 1; i++) //
    {
        cout << "|"; // |   |   |   |
        for (int j = 1; i <= size; j++)
        {
            cout << "   |";
        }

        cout << endl;

        cout << "|"; // |---+---+---|
        for (int j = 1; i < size; j++)
        {
            cout << "---+";
        }

        cout << "---|";
        cout << endl;
    }

    cout << "|"; // |   |   |   |
    for (int i = 1; i <= size; i++)
    {
        cout << "   |";
    }
    cout << endl;
    cout << "-----"; // -------------
    for (int i = 1; i < size; i++) //bottom line
    {
        cout << "----";
    }
    
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