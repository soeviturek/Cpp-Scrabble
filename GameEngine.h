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
    void setPlayerScore(Player* player, int score);
    void setPlayerName(Player* player, std::string name);
    
    /* Gameplay functions */
    void placeTile(Tile* tile, int row, int col); //place a tile at ?,? coordinates

    //calculate total scores after placing tiles
    //tiles placed are kept in the vector, it will check horizontally and vertically
    //it should first gets what rows and cols, without repitition need to be checked
    //then it checks the rows and cols, it stops when hit the boundary of board
    //or hits an empty square.
    int calculateScore(std::vector<Tile*> tiles); //calculate the total score after placing tiles
    void checkVertical(int col);
    void checkHorizontal(int row);
    


    void replaceTile(Tile* tile); //replace a tile, check if the tile is in hand, check if there is any in the bag
    Tile* drawTile(); //get a copy of tile from tileBag, add to hand, remove it from tileBag
    
    std::string displayBoard(); //returns a string the board status

    void saveGame(std::string fileName); //saves the current game, after saving game continues
    bool loadGame(std::string fileName);//check file exists, check format
    bool gameOver(); //print "Game Over", print "Score for {player name}: " score, print "Player <winniner player name> won!"
    void quit(); //

    private:
    std::vector<Player*> players;
    TileBag* tileBag;

    bool checkPlayerNameValidity(std::string name); //check if the name only contains letters
    bool checkBagEmpyty(); //check if the tile bag is empty
    bool checkPlayerHandEmpty(); //check if player's hand is empty
    bool checkPlayerPassStatus(); //check if a player has passed his turn twice
    bool checkBingo(); //add bonus 50 points, should be called after placement
    bool checkEnd();//1. the bag is empty and 1. a player's hand is empty or 2. a player has passed his turn twice
    int convertLetterToNum(char letter); //convert letter to number, used to convert input letter to number coordinates
    //place tile at A1 A->0
    //vector[int][int]
};


#endif //ASSIGN2_ENGINE_H