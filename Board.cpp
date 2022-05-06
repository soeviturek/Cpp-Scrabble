#include "Board.h"

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
        boardStatus += add; // convert number to letter
        boardStatus += "  |";
        //string.append(char)
        for(int j = 0; j < DEFAULT_DIMENSION; ++j){
            if(board[i][j] == nullptr){
                boardStatus += "   |";
            }else{
                Tile* tile = board[i][j];
                boardStatus += ' ';
                boardStatus +=tile->letter;
                boardStatus += " |";
            }
        }
        boardStatus += "\n";
    }
    return boardStatus;
}

char Board::getSquare(int row, int col){
    return board[row][col]->letter;
}
void Board::placeTile(Tile* tile, int row, int col){
    board[row][col] = tile;
}
