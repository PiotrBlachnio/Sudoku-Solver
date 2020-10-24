#include "board.h"

Board::Board(std::string boardString = SKIP_CONTRUCTOR_CHARACTER) {
    if(boardString == SKIP_CONTRUCTOR_CHARACTER) return;
    
    int charactersNumber = boardString.size();

    if(charactersNumber != BOARD_CHARACTERS_NUMBER) throw InvalidBoardStringException();
    if(!isNumerical(boardString)) throw InvalidBoardStringException();

    convertStringToBoard(boardString);
}

std::vector<std::vector<int>> Board::getBoard() {
    return _board;
}

void Board::printBoard() {
    for(int rowIndex = 0; rowIndex < _board.size(); rowIndex++) {
        if(rowIndex != 0) std::cout << "\n - - - - - - - - -\n";

        for(int square : _board[rowIndex]) {
            std::cout << square << " ";
        }
    }
}

void Board::convertStringToBoard(std::string input) {
    int currentCharIndex = 0;

    for(int i = 0; i < 9; i++) {
        std::vector<int> row;

        for(int j = 0; j < 9; j++) {
            row.push_back((input[currentCharIndex] - ASCII_CODE_BASE));
            currentCharIndex++;
        }

        _board.push_back(row);
    }
}

bool Board::isNumerical(std::string input) {
    std::smatch match;
    std::regex reg("^[0-9]*$");

    return std::regex_search(input, match, reg);
}