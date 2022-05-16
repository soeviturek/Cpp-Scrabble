/* Represents the game engine
@author Yuchen Wu
*/
#ifndef ASSIGN2_ENGINE_H
#define ASSIGN2_ENGINE_H
#define MAX_PLAYERS 2
#include "Player.h"
#include "TileBag.h"
#include "Board.h"
#include <vector>
#include <fstream>

class GameEngine{
    public:
    GameEngine();
    ~GameEngine();

    /*starts game, while not end, take turn ask each player to:
    *show current player and status
    *check if player wants to: 
    1.place tile: Words are played either vertically or horizontally. Diagonal word play is not permitted. 
    The letters placed must form complete words. Anytime two or more letters touch, they must form valid, legal words.
    All letters placed need to be connected to another already on board.
    Keep record of the  tiles played and the position they are placed
    Check if the location already has a tile placed
    Cehck if the first letter placed is connected to a tile
    Check if tiles placed are on the same row/column

    Place tile, update the board
    Calculate score, when calculating, iterate through every tile placed, check its horizontal and vertical direction for words, add up their values
    2.replace tile: replace a single tile in this game
    check if that tile exists
    check if there is a enough tile in the tile bag
    swap the first tile in the hand if multiple exist
    3.pass: do nothing
    4.save game:
    5.load game:



    */
    void newGame(); 
    void setupGame();//initiate tilebag, board, players' hands

    bool addPlayer(std::string playerName);
    

    /* calculate total scores after placing tiles
     * rules: tiles placed are kept in the vector, it will check horizontally and vertically
     * it should first gets what rows and cols, without repitition need to be checked
     * then it checks the rows and cols, it stops when hit the boundary of board
     * or hits an empty square. */
    int calculateScore(std::vector<int> rows,std::vector<int> cols, int direction);
    

    //replace a tile, check if the tile is in hand, check if there is any in the bag
    bool replaceTile(Tile* tile); 
    //get a copy of tile from tileBag, add to hand, remove it from tileBag
    Tile* drawTile(); 

    //saves the current game, after saving game continues
    void saveGame(std::string fileName); 

    //check file exists, check format
    bool loadGame(std::string fileName);



    //print "Game Over", print "Score for {player name}: " score, print "Player <winniner player name> won!" 
    void endGame();
    void quit();
    //switch player
    void switchPlayer();

    private:
    std::vector<Player*> players;
    int currentPlayerIndex;
    TileBag* tileBag;
    Board* board;
    //check if the name only contains uppercase letters
    bool checkPlayerNameValidity(std::string name); 
    
    //check if game is over
    bool gameOver();

    //convert letter to number, used to convert input letter to number coordinates
    int convertLetterToNum(char letter); 
};


#endif //ASSIGN2_ENGINE_H