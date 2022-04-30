#include "Board.h"

Board::Board(){
    for(int i = 0; i < DEFAULT_DIMENSION; ++i){
        std::vector<char> rowVector;
        for(int j = 0; j < DEFAULT_DIMENSION; ++j){
            rowVector.push_back(0);
        }
        board.push_back(rowVector);
    }
}