#include <iostream>
#include "board.h"
using namespace std;

int main()
{
    cout << "All solutions to the 8 Queens Puzzle:\n\n";

    vector<vector<int>> board(8, vector<int>(8, 0));

    solveNQueens(board);

    return 0;
}