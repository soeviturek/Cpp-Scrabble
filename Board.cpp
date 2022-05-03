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
std::string Board::printBoard(){
    std::string boardStatus = "";
    for(int i = 0; i < DEFAULT_DIMENSION; ++i){
        boardStatus += ""; // convert number to letter
        //string.append(char)
        for(int j = 0; j < DEFAULT_DIMENSION; ++j){
            if(board[i][j] == nullptr){
                boardStatus += "   ";
            }
        }
        boardStatus += "|\n";
    }
    return boardStatus;
}