/* Represents a board
@author Yuchen Wu
*/

#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H
#include <vector>
#include <string>
#define DEFAULT_DIMENSION 15

class Board{
    public:
    Board();
    ~Board();
    std::string printBoard();
    char getSquare(int row, int col);

    private:
    std::vector<std::vector<char>> board;
    int row;
    int col;
    

};

#endif // ASSIGN2_Board_H