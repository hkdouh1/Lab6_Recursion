#ifndef BOARD_H
#define BOARD_H

#include <vector>
using namespace std;

// function that prints the board
void printBoard(const vector<vector<int>>& board);

// recursive function to solve the puzzle
void solveNQueensUtil(int col, vector<vector<int>>& board, vector<int>& leftRow,
    vector<int>& upperDiagonal, vector<int>& lowerDiagonal);

// main function to solve the puzzle
void solveNQueens(vector<vector<int>>& board);

#endif