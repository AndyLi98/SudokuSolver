#include <iostream>
#include "SudokuSolver.hpp"

int main() {
  // Initialize the SudokuSolver with an input file

  SudokuSolver hi;

  hi.display();
  std::cout << "Test param" << std::endl;
  SudokuSolver solver("puzzle1.csv");

  // Display the initial puzzle
  
  solver.display();

}

