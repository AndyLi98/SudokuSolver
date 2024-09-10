#include "SudokuSolver.hpp"

//default constructor allocates memory
SudokuSolver::SudokuSolver() {
    // allocate memory for the 2D array and initialize to 0
    puzzle_ = new int*[9];
    for (int i = 0; i < 9; ++i) {
        puzzle_[i] = new int[9]();
    }
    solvable_ = false;
}
//param constructor allocates memory for value coming from files
SudokuSolver::SudokuSolver(std::string input_file) {
    puzzle_ = new int*[9];
    for (int i = 0; i < 9; ++i) {
    puzzle_[i] = new int[9];
    }
    std::ifstream file(input_file);
    if (file.is_open()) {
    std::string line;
    int row = 0;
    while (std::getline(file, line)) {
        int col = 0;
        std::stringstream ss(line);
        std::string token;
        while (std::getline(ss, token, ',')) {
            puzzle_[row][col] = std::stoi(token);
            ++col;
        }
        ++row;
    }
    solvable_ = solvePuzzle();
    } 
    else{
    std::cerr << "Unable to open file: " << input_file << std::endl;
    solvable_ = false;
    }
}

//solve the puzzle using helper functions checkLegalValue, recrusively calls itself
//until a valid value
bool SudokuSolver::solvePuzzle() {
  Sudoku::Location location = returnNextEmpty();
  if (location.row == -1 && location.col == -1) {
    // There are no more empty squares, so the puzzle is solved
    return true;
  }
  
  for (int value = 1; value <= 9; ++value) {
    if (checkLegalValue(value, location)) {
      // The value is legal, so we can fill the square with it
      puzzle_[location.row][location.col] = value;
      
      if (solvePuzzle()) {
        // We have found a solution
        return true;
      }
      
      // The current value did not lead to a solution, so we backtrack
      puzzle_[location.row][location.col] = 0;
    }
  }
  
  // None of the values led to a solution, so the puzzle is unsolvable
  return false;
}



bool SudokuSolver::isPuzzleSolvable() const {
    return solvable_;
}

void SudokuSolver::setSolvable() {
    solvable_ = true;
}

int** SudokuSolver::getPuzzleNumbers() const {
    return puzzle_;
}

void SudokuSolver::setPuzzleNumbers(int** puzzle) {
    puzzle_ = puzzle;
}

Sudoku::Location SudokuSolver::returnNextEmpty() const {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (puzzle_[i][j] == 0) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

//check is value has no other same value in same row column or in the same subgrid
bool SudokuSolver::checkLegalValue(int value, Sudoku::Location location) const
{
  // Check if value already exists in the same row
  for (int col = 0; col < 9; col++) {
    if (puzzle_[location.row][col] == value) {
      return false;
    }
  }
  
  // Check if value already exists in the same column
  for (int row = 0; row < 9; row++) {
    if (puzzle_[row][location.col] == value) {
      return false;
    }
  }
  
  // Check if value already exists in the same sub-grid
  int sub_grid_row = (location.row / 3) * 3;
  int sub_grid_col = (location.col / 3) * 3;
  for (int row = sub_grid_row; row < sub_grid_row + 3; row++) {
    for (int col = sub_grid_col; col < sub_grid_col + 3; col++) {
      if (puzzle_[row][col] == value) {
        return false;
      }
    }
  }
  
  // If all checks pass, then the value is legal
  return true;
}

//display the puzzle 
void SudokuSolver::display(){
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i != 0) {
            std::cout << "- - - - - - - - - - - -\n";
        }
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0 && j != 0) {
                std::cout << " | ";
            }
            if (puzzle_[i][j] == 0) {
                std::cout << "X ";
            } else {
                std::cout << puzzle_[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
}


