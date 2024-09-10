#ifndef SUDOKU_SOLVER_HPP_
#define SUDOKU_SOLVER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

namespace Sudoku
{ 
  struct Location
  {
    int row;
    int col;
  };
}

class SudokuSolver
{
public:

//constructors
SudokuSolver();
SudokuSolver(std::string input_file);

//Accessor and mutators
bool isPuzzleSolvable() const;
void setSolvable();
int** getPuzzleNumbers() const;
void setPuzzleNumbers(int** puzzle);


Sudoku::Location returnNextEmpty() const;
bool checkLegalValue(int value, Sudoku::Location location) const;
void display();
bool solvePuzzle();


private:
int** puzzle_;
bool solvable_;
};

#endif
