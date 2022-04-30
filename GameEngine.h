/* Represents the game engine
@author Yuchen Wu
*/
#ifndef ASSIGN2_ENGINE_H
#define ASSIGN2_ENGINE_H
#include "Player.h"
#include "TileBag.h"
#include "Board.h"

class GameEngine{
    public:
    GameEngine();
    ~GameEngine();

    void newGame(); //initiate tilebag, board
    void setupGame();

    //game starts, each player draws 7 tiles to his hand.. those tiles are also removed from tile


    void addPlayer(std::string playerName);
    void setPlayerScore(Player* player, int score);
    void setPlayerName(Player* player, std::string name);

    void placeTile(); //place a tile
    int calculateScore(); //calculate the total score after placing tiles
    void replaceTile(); //replace a tile, check if the tile is in hand, check if there is any in the bag
    void drawCard(); //draw a card
    
    std::string displayBoard(); //returns a string the board to be printed

    void saveGame(std::string fileName); //saves the current game, after saving game continues
    bool loadGame(std::string fileName);//check file exists, check format
    bool gameOver(); //print "Game Over", print "Score for {player name}: " score, print "Player <winniner player name> won!"
    void quit(); //

    private:
    Player* player1;
    Player* player2;
    TileBag* tileBag;

    bool playerNameCheck(std::string name); //check if the name only contains letters
    bool checkBagEmpyty(); //check if the tile bag is empty
    bool checkBingo(); //add bonus 50 points, should be called after placement
    bool checkEnd();//1. the bag is empty and 1. a player's hand is empty or 2. a player has passed his turn twice
    int convertLetterToNum(char letter);
};


#endif //ASSIGN2_ENGINE_H