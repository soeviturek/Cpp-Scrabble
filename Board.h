/* Represents a board
@author Yuchen Wu
*/

#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H
#include <vector>

class Board{
    public:
    Board(int row, int col);
    ~Board();
    Board getBoard();
    char getSquare(int row, int col);

    private:
    std::vector<std::vector<char>> board;
    int row;
    int col;
    

};

#endif // ASSIGN2_Board_H