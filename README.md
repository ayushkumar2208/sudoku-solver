# Sudoku Solver

A Complete Sudoku Puzzle Solver Built In C++ Using Backtracking Algorithm.

## Overview

This Program Solves Any Valid Sudoku Puzzle Using Recursive Backtracking. It Validates All Sudoku Rules (Row, Column, And 3x3 Subgrid Constraints) Before Placing A Number. The Solver Can Load Puzzles From Files Or Accept Manual Input.

## Features

- **Backtracking Algorithm**: Recursive Approach To Find Valid Solutions
- **Input Methods**: Manual Entry Or Load From File
- **Validation**: Checks Row, Column, And Subgrid Constraints
- **Display**: Formatted Grid Display With Separators
- **File Handling**: Save And Load Puzzles
- **User-Friendly**: Menu-Driven Console Interface
- **Error Handling**: Validates Input And Provides Error Messages

## Project Structure

```
sudoku-solver/
├── sudoku.h (Sudoku Class Header)
├── sudoku.cpp (Sudoku Class Implementation)
├── main_sudoku.cpp (Main Program)
├── puzzle.txt (Sample Puzzle File)
├── solution.txt (Generated Solution File)
├── .gitignore
└── README.md
```

## Files Description

### sudoku.h
- Class Declaration For Sudoku Solver
- Private Members: Grid (9x9 Vector), SIZE, SUBGRID_SIZE
- Private Methods: Validation Functions (isRowSafe, isColSafe, isSubgridSafe, isValid)
- Public Methods: Input, Display, Solve, File Operations

### sudoku.cpp
- Sudoku Class Implementation
- Backtracking Algorithm Implementation
- Validation Logic For Sudoku Rules
- File I/O Operations
- Grid Display With Formatting

### main_sudoku.cpp
- Main Program Entry Point
- Menu-Driven Interface
- User Interaction Logic
- Option Handling

### puzzle.txt
- Sample Sudoku Puzzle For Testing
- Format: 9 Rows Of 9 Numbers Each (0 = Empty Cell)

## How To Compile

Using G++ Compiler:

```bash
g++ -o sudoku main_sudoku.cpp sudoku.cpp
```

Alternative With C++11:

```bash
g++ -std=c++11 -o sudoku main_sudoku.cpp sudoku.cpp
```

## How To Run

Windows:
```bash
sudoku.exe
```

Linux/Mac:
```bash
./sudoku
```

## Usage Guide

### Menu Options

1. **Input Puzzle Manually**
   - Enter 9 Rows Of 9 Numbers Each
   - Use 0 For Empty Cells
   - Numbers Must Be 1-9 Or 0

2. **Load Puzzle From File**
   - Enter Filename (e.g., puzzle.txt)
   - File Should Have 9 Rows Of 9 Numbers
   - Space-Separated Format

3. **Display Current Puzzle**
   - Shows Current Grid State
   - Formatted With Borders
   - Dots Represent Empty Cells

4. **Solve Sudoku**
   - Solves The Loaded Or Entered Puzzle
   - Uses Backtracking Algorithm
   - Displays Solution If Found
   - Shows Message If No Solution Exists

5. **Save Solution To File**
   - Saves Solved Puzzle To File
   - Works Only After Solving
   - Enter Desired Filename

6. **Reset Grid**
   - Clears All Grid Data
   - Prepares For New Puzzle

7. **Exit**
   - Closes Application

## Sample Puzzle Input

```
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

## Algorithm Explanation

### Backtracking Algorithm

1. Start From First Cell (0,0)
2. For Each Empty Cell:
   - Try Numbers 1-9
   - Check If Number Is Valid (Row, Column, Subgrid Rules)
   - If Valid, Place Number
   - Recursively Move To Next Cell
   - If Stuck, Backtrack And Try Different Number
3. Return True When All Cells Filled Successfully

### Validation Rules

- **Row Constraint**: No Duplicate Numbers In Same Row
- **Column Constraint**: No Duplicate Numbers In Same Column
- **Subgrid Constraint**: No Duplicate Numbers In 3x3 Subgrid

## Time Complexity

- **Best Case**: O(N^2) - Puzzle Already Nearly Solved
- **Average Case**: O(N^(N^2)) - Depends On Puzzle Difficulty
- **Worst Case**: O(N^(N^2)) - Very Hard Puzzles

## Space Complexity

- O(N^2) For Grid Storage
- O(N^2) For Recursion Call Stack

## Key Functions

### isRowSafe(int row, int num)
Checks If Number Exists In Given Row

### isColSafe(int col, int num)
Checks If Number Exists In Given Column

### isSubgridSafe(int row, int col, int num)
Checks If Number Exists In 3x3 Subgrid

### isValid(int row, int col, int num)
Validates All Three Constraints

### solve(int row, int col)
Recursive Backtracking Implementation

### solveSudoku()
Wrapper Function That Initiates Solving

## Example Walkthrough

1. Run Program → Main Menu Displayed
2. Option 2 → Load Puzzle From File
3. Enter "puzzle.txt"
4. Option 4 → Solve Sudoku
5. Solution Displayed
6. Option 5 → Save Solution
7. Enter "solution.txt"
8. Solution Saved To File
9. Option 7 → Exit Program

## File Format

### Puzzle File Format
- 9 Rows Of Numbers
- Space-Separated Values
- 0 Represents Empty Cells
- Valid Range: 0-9

### Solution File Format
- Same As Puzzle File
- Saved After Solving
- All Cells Filled (No Zeros)

## Features Implemented

✅ 2D Vector Grid Representation
✅ Backtracking Algorithm
✅ Row Validation
✅ Column Validation
✅ 3x3 Subgrid Validation
✅ Manual Input
✅ File Loading
✅ File Saving
✅ Formatted Grid Display
✅ Menu-Driven Interface
✅ Error Handling
✅ Input Validation

## Technical Details

- **Language**: C++
- **Standard**: C++11 Or Later
- **Data Structure**: 2D Vector (9x9)
- **Algorithm**: Backtracking With Recursion
- **File I/O**: ifstream And ofstream
- **Compilation**: G++ Compiler
- **Platform**: Windows, Linux, Mac

## Sudoku Rules (Implemented)

1. Each Row Must Contain Numbers 1-9 Exactly Once
2. Each Column Must Contain Numbers 1-9 Exactly Once
3. Each 3x3 Subgrid Must Contain Numbers 1-9 Exactly Once
4. All Constraints Must Be Satisfied Simultaneously

## Limitations And Future Enhancements

### Current Limitations
- No GUI (Console Only)
- Single Solver Method (Backtracking)
- No Difficulty Analysis
- No Puzzle Generation

### Future Enhancements
- GUI Implementation Using Qt Or SFML
- Multiple Solving Algorithms (Constraint Propagation)
- Puzzle Difficulty Rating
- Automatic Puzzle Generator
- Performance Optimization
- Visual Solution Animation
- Hint System
- Step-By-Step Solving Display

## Compilation Examples

### Basic Compilation
```bash
g++ -o sudoku main_sudoku.cpp sudoku.cpp
./sudoku
```

### With Optimization
```bash
g++ -O2 -o sudoku main_sudoku.cpp sudoku.cpp
./sudoku
```

### With Debugging
```bash
g++ -g -o sudoku main_sudoku.cpp sudoku.cpp
gdb ./sudoku
```

## Troubleshooting

### Compilation Errors
- Ensure G++ Is Installed
- Check File Paths Are Correct
- Verify All Files In Same Directory

### Runtime Issues
- Verify puzzle.txt Has Correct Format
- Check All Numbers Are 0-9
- Ensure File Has 9 Rows Of 9 Numbers

### No Solution Found
- Verify Puzzle Is Valid
- Check For Duplicate Numbers In Rows/Columns
- Ensure Puzzle Follows Sudoku Rules

## Performance Notes

- Solving Takes 1-5 Seconds For Most Puzzles
- Very Hard Puzzles May Take Longer
- Performance Depends On Puzzle Difficulty
- Backtracking Is Efficient For Most Cases

## Author

Ayush Kumar
UPES Dehradun - B.Tech CSE (Data Science)

## License

Open Source - Free To Use And Modify

## Conclusion

This Sudoku Solver Demonstrates Effective Use Of Backtracking Algorithm And Recursive Problem-Solving. It's A Great Educational Project For Learning Algorithms And Data Structures. The Code Is Clean, Well-Structured, And Easy To Understand.
