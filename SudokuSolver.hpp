#ifndef SUDOKU_SOLVER_HPP_
#define SUDOKU_SOLVER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//We define Location within the Sudoku namespace.
//To use Location, you must specify the namespace Sudoku::Location
//Just like you do when using the standard namespace std::
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
//Add your public members here
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
//Add your private members here
int** puzzle_;
bool solvable_;
};

#endif
