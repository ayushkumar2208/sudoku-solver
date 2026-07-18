#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "sudoku.h"

using namespace std;

void displayMainMenu()
{
    cout << "\n=========================================\n";
    cout << "         SUDOKU SOLVER\n";
    cout << "=========================================\n";
    cout << "1.  Input Puzzle Manually\n";
    cout << "2.  Load Puzzle From File\n";
    cout << "3.  Display Current Puzzle\n";
    cout << "4.  Solve Sudoku\n";
    cout << "5.  Save Solution To File\n";
    cout << "6.  Reset Grid\n";
    cout << "7.  Exit\n";
    cout << "=========================================\n";
    cout << "Enter Your Choice: ";
}

void pauseScreen()
{
    cout << "\nPress Enter To Continue...";
    cin.ignore();
    cin.get();
}

int main()
{
    Sudoku sudoku;
    int choice;
    bool solved = false;

    cout << "\n=========================================\n";
    cout << "     WELCOME TO SUDOKU SOLVER\n";
    cout << "=========================================\n";
    cout << "\nSystem Initialized Successfully!\n";

    while (true)
    {
        displayMainMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\n---------- INPUT PUZZLE MANUALLY ----------\n";
            sudoku.inputPuzzle();
            solved = false;
            pauseScreen();
            break;
        }

        case 2:
        {
            cout << "\n---------- LOAD PUZZLE FROM FILE ----------\n";
            string filename;
            cout << "Enter Filename (e.g., puzzle.txt): ";
            cin >> filename;
            sudoku.loadFromFile(filename);
            solved = false;
            pauseScreen();
            break;
        }

        case 3:
        {
            cout << "\n---------- CURRENT PUZZLE ----------\n";
            sudoku.displayGrid();
            pauseScreen();
            break;
        }

        case 4:
        {
            cout << "\n---------- SOLVING SUDOKU ----------\n";
            cout << "Solving... Please Wait...\n";
            
            if (sudoku.solveSudoku())
            {
                cout << "\nSudoku Solved Successfully!\n";
                cout << "\n========== SOLUTION ==========\n";
                sudoku.displayGrid();
                solved = true;
            }
            else
            {
                cout << "\nNo Solution Exists For This Puzzle!\n";
                cout << "Please Check Your Input And Try Again.\n";
                solved = false;
            }
            
            pauseScreen();
            break;
        }

        case 5:
        {
            if (solved)
            {
                cout << "\n---------- SAVE SOLUTION ----------\n";
                string saveFilename;
                cout << "Enter Filename To Save (e.g., solution.txt): ";
                cin >> saveFilename;
                sudoku.saveToFile(saveFilename);
                pauseScreen();
            }
            else
            {
                cout << "\nPlease Solve The Sudoku First!\n";
                pauseScreen();
            }
            break;
        }

        case 6:
        {
            cout << "\n---------- RESET GRID ----------\n";
            sudoku.resetGrid();
            solved = false;
            pauseScreen();
            break;
        }

        case 7:
        {
            cout << "\n=========================================\n";
            cout << "Thank You For Using Sudoku Solver!\n";
            cout << "Exiting Program...\n";
            cout << "=========================================\n";
            return 0;
        }

        default:
        {
            cout << "\nInvalid Choice! Please Enter a Valid Option (1-7).\n";
            pauseScreen();
        }
        }
    }

    return 0;
}
