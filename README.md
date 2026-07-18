# Sudoku Solver

A C++ implementation of a Sudoku Solver using the Backtracking Algorithm. The project demonstrates recursion, constraint validation, file handling, and object-oriented programming concepts.

## Features

- Solve Sudoku puzzles using Backtracking
- Manual puzzle input
- Load puzzle from a file
- Save solved puzzle to a file
- Row, Column, and 3×3 Subgrid validation
- Formatted grid display
- Menu-driven console interface

## Project Structure

```
sudoku-solver/
├── sudoku.h
├── sudoku.cpp
├── main.cpp
├── puzzle.txt
├── .gitignore
└── README.md
```

## Requirements

- C++11 or later
- G++ Compiler

## Compilation

```bash
g++ -std=c++11 -o sudoku main.cpp sudoku.cpp
```

## Run

### Windows

```bash
sudoku.exe
```

### Linux / macOS

```bash
./sudoku
```

## Usage

1. Enter a puzzle manually or load it from `puzzle.txt`.
2. Display the puzzle.
3. Solve the puzzle using the Backtracking algorithm.
4. Save the solved puzzle if required.

## Sample Puzzle

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

## Algorithm

The solver uses a recursive Backtracking approach:

- Find the next empty cell.
- Try numbers from 1 to 9.
- Validate against Sudoku rules.
- Continue recursively.
- Backtrack if no valid number can be placed.

## Validation Rules

- No duplicate numbers in any row.
- No duplicate numbers in any column.
- No duplicate numbers in any 3×3 subgrid.

## Complexity

- **Time Complexity:** Exponential (depends on puzzle difficulty)
- **Space Complexity:** O(81) for recursion and board storage

## Technologies Used

- C++
- Object-Oriented Programming
- Backtracking Algorithm
- Recursion
- File Handling
- STL

## Future Improvements

- Graphical User Interface
- Puzzle Generator
- Difficulty Levels
- Hint System
- Step-by-Step Visualization
- Performance Optimization

## Author

**Ayush Kumar**

B.Tech CSE (Data Science)

UPES Dehradun

## License

Open Source for educational purposes.
