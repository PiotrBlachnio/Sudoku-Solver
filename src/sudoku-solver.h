#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

    #include <vector>

    class SudokuSolver {
        public:
            SudokuSolver(std::vector<std::vector<int>> board);

            std::vector<std::vector<int>> solve();
        private:
            const std::vector<std::vector<int>> board;

            Square findEmptySquare();

            bool isSquareValid(Square square);

            bool isRowValid(int rowIndex, int number);

            bool isColumnValid(int columnIndex, int number);
    };

    struct Square {
        int row;
        int column;

        Square(int row, int column) {
            row = row;
            column = column;
        }
    };

#endif