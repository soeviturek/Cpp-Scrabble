/* Represents a board
@author Yuchen Wu
*/

#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H
#include <vector>
#include <string>
#include "Tile.h"
#define DEFAULT_DIMENSION 15

class Board{
    public:
    Board();
    ~Board();
    std::string printBoard();
    char getSquare(int row, int col);
    void placeTile(Tile* tile, int row, int col);
    private:
    std::vector<std::vector<Tile*>> board;
    int row;
    int col;
    

};

#endif // ASSIGN2_Board_H