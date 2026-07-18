#include "sudoku.h"
#include <fstream>
#include <iomanip>

Sudoku::Sudoku()
{
    grid.resize(SIZE, vector<int>(SIZE, 0));
}

void Sudoku::displayGrid()
{
    cout << "\n";
    cout << "  +-------+-------+-------+\n";
    
    for (int row = 0; row < SIZE; row++)
    {
        if (row % 3 == 0 && row != 0)
        {
            cout << "  +-------+-------+-------+\n";
        }

        cout << "  | ";

        for (int col = 0; col < SIZE; col++)
        {
            if (col % 3 == 0 && col != 0)
            {
                cout << "| ";
            }

            if (grid[row][col] == 0)
            {
                cout << ". ";
            }
            else
            {
                cout << grid[row][col] << " ";
            }
        }

        cout << "|\n";
    }

    cout << "  +-------+-------+-------+\n";
}

bool Sudoku::isRowSafe(int row, int num)
{
    for (int col = 0; col < SIZE; col++)
    {
        if (grid[row][col] == num)
        {
            return false;
        }
    }
    return true;
}

bool Sudoku::isColSafe(int col, int num)
{
    for (int row = 0; row < SIZE; row++)
    {
        if (grid[row][col] == num)
        {
            return false;
        }
    }
    return true;
}

bool Sudoku::isSubgridSafe(int row, int col, int num)
{
    int startRow = row - row % SUBGRID_SIZE;
    int startCol = col - col % SUBGRID_SIZE;

    for (int i = startRow; i < startRow + SUBGRID_SIZE; i++)
    {
        for (int j = startCol; j < startCol + SUBGRID_SIZE; j++)
        {
            if (grid[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::isValid(int row, int col, int num)
{
    return isRowSafe(row, num) && isColSafe(col, num) && isSubgridSafe(row, col, num);
}

bool Sudoku::solve(int row, int col)
{
    if (row == SIZE)
    {
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;

    if (nextCol == SIZE)
    {
        nextRow++;
        nextCol = 0;
    }

    if (grid[row][col] != 0)
    {
        return solve(nextRow, nextCol);
    }

    for (int num = 1; num <= SIZE; num++)
    {
        if (isValid(row, col, num))
        {
            grid[row][col] = num;

            if (solve(nextRow, nextCol))
            {
                return true;
            }

            grid[row][col] = 0;
        }
    }

    return false;
}

bool Sudoku::solveSudoku()
{
    return solve(0, 0);
}

void Sudoku::inputPuzzle()
{
    cout << "\n========== INPUT SUDOKU PUZZLE ==========\n";
    cout << "Enter 9 rows of 9 numbers each (0 for empty cells)\n";
    cout << "=========================================\n\n";

    for (int row = 0; row < SIZE; row++)
    {
        cout << "Enter Row " << (row + 1) << ": ";
        
        for (int col = 0; col < SIZE; col++)
        {
            cin >> grid[row][col];

            if (grid[row][col] < 0 || grid[row][col] > 9)
            {
                cout << "\nInvalid Input! Enter Numbers Between 0-9\n";
                grid[row][col] = 0;
                col--;
            }
        }
    }

    cout << "\n========== PUZZLE LOADED ==========\n";
    displayGrid();
}

void Sudoku::loadFromFile(const string& filename)
{
    ifstream file(filename);

    if (!file)
    {
        cout << "\nError: Unable To Open File " << filename << "\n";
        return;
    }

    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            file >> grid[row][col];
        }
    }

    file.close();
    cout << "\nPuzzle Loaded From " << filename << "\n";
    displayGrid();
}

void Sudoku::saveToFile(const string& filename)
{
    ofstream file(filename);

    if (!file)
    {
        cout << "\nError: Unable To Create File " << filename << "\n";
        return;
    }

    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            file << grid[row][col];
            if (col < SIZE - 1)
            {
                file << " ";
            }
        }
        file << "\n";
    }

    file.close();
    cout << "\nSolution Saved To " << filename << "\n";
}

bool Sudoku::isComplete()
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (grid[row][col] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void Sudoku::resetGrid()
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            grid[row][col] = 0;
        }
    }
    cout << "\nGrid Reset Successfully!\n";
}
