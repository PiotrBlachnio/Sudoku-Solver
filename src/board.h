#ifndef BOARD_H
#define BOARD_H
 
    #include "exceptions/invalid-board-string.exception.h"
    #include "square.h"
    #include "utils.h"
    #include <vector>
    #include <string>
    #include <iostream>

    struct Board {
        Board(std::string boardString);

        const static int ROW_LENGTH = 9;
        std::vector<std::vector<int>> data;

        void printBoard();
        void insertSquare(Square square);

        std::optional<Square> findEmptySquare();
        std::vector<std::vector<int>> convertStringToBoard(std::string boardString);
        std::string convertBoardToString();
        std::vector<int> getRowByIndex(int index);

        private:
            const static int BOARD_CHARACTERS_NUMBER = 81;
            const static int ASCII_CODE_BASE = 48;
    };

#endif