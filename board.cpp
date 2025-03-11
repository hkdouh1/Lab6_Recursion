#include <iostream>
#include "board.h"
using namespace std;

// function that will print the board
void printBoard(const vector<vector<int>>& board) 
{
    for (const auto& row : board)
    {
        for (int cell : row)
        {
            cout<<(cell ? "Q " : ". ");
        }
        cout<< endl;
    }
    cout<< endl;
}


bool isSafe(int row, int col, const vector<int>& leftRow, const vector<int>& upperDiagonal, const vector<int>& lowerDiagonal)
{
    // to see if the rows are taken
    if (leftRow[row] || upperDiagonal[row + col] || lowerDiagonal[col - row + 7])
    {
        return false;
    }
    return true;
}

// the recursive function to solve the puzzle
void solveNQueensUtil(int col, vector<vector<int>>& board, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal)
{
    if (col == 8)
    {
        printBoard(board);
        return;
    }

    for (int row = 0; row < 8; ++row) // placing a queen in row by row
    {
        if (isSafe(row, col, leftRow, upperDiagonal, lowerDiagonal))
        {
        
            board[row][col] = 1;
            leftRow[row] = 1;
            upperDiagonal[row + col] = 1;
            lowerDiagonal[col - row + 7] = 1;

            solveNQueensUtil(col + 1, board, leftRow, upperDiagonal, lowerDiagonal);

            board[row][col] = 0;
            leftRow[row] = 0;
            upperDiagonal[row + col] = 0;
            lowerDiagonal[col - row + 7] = 0;
        }
    }
}

void solveNQueens(vector<vector<int>>& board)
{
    vector<int> leftRow(8, 0);
    vector<int> upperDiagonal(15, 0);
    vector<int> lowerDiagonal(15, 0);

    solveNQueensUtil(0, board, leftRow, upperDiagonal, lowerDiagonal);
}