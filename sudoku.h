#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <vector>

using namespace std;

class Sudoku
{
private:
    vector<vector<int>> grid;
    static const int SIZE = 9;
    static const int SUBGRID_SIZE = 3;

    bool isValid(int row, int col, int num);
    bool isRowSafe(int row, int num);
    bool isColSafe(int col, int num);
    bool isSubgridSafe(int row, int col, int num);

public:
    Sudoku();
    
    void inputPuzzle();
    void displayGrid();
    bool solveSudoku();
    bool solve(int row, int col);
    
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename);
    
    bool isComplete();
    void resetGrid();
};

#endif
