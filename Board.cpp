#include "Board.h"
#include <iostream>
Board::Board(){
    for(int i = 0; i < DEFAULT_DIMENSION; ++i){
        std::vector<Tile*> rowVector;
        for(int j = 0; j < DEFAULT_DIMENSION; ++j){
            rowVector.push_back(nullptr);
        }
        board.push_back(rowVector);
    }
}
Board::~Board(){
    for(int i = 0; i < DEFAULT_DIMENSION; ++i){
        for(int j = 0; j < DEFAULT_DIMENSION; ++j){
            if(board[i][j] != nullptr){
                delete board[i][j];
            }
        }
    }
}
std::string Board::printBoard(){
    std::string boardStatus = "     0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  \n   -------------------------------------------------------------\n";
    for(int i = 0; i < DEFAULT_DIMENSION; ++i){
        char add = 'A'+i;
        boardStatus += add;
        boardStatus += "  |";
        for(int j = 0; j < DEFAULT_DIMENSION; ++j){
            Tile* tile = board[i][j];
            if(tile == nullptr){
                boardStatus += "   ";
            }else{
                boardStatus += " ";
                boardStatus +=tile->letter;
                boardStatus += " ";
            }
            boardStatus += "|";
        }
        boardStatus += "\n";
    }
    return boardStatus;
}

char Board::getSquare(int row, int col){
    Letter letter = ' ';
    if(row < 0 || col < 0 || row > DEFAULT_DIMENSION-1 || col > DEFAULT_DIMENSION-1){
        letter = '?';
    }
    else if(board[row][col] != nullptr){
        letter = board[row][col]->letter;
    }
    return letter;
}
void Board::placeTile(Tile* tile, int row, int col){
    board[row][col] = tile;
}
