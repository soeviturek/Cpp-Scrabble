/* Represents a player
@author Yuchen Wu
*/

#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H
#include <string>
#include "Hand.h"

class Player{
    public:
    Player(std::string playerName);
    ~Player();
    //player gameplay
    void placeTile(Tile* tile, int row, int col);
    void replaceTile(Tile* tile, Tile* replacement);
    void pass();
    std::string printHand();

    //player settings
    void setScore(int score);
    void setName(std::string playerName);
    void setHand(Hand* hand);
    Hand* getHand();
    std::string getName();
    int getScore();
    

    void setPassTime(int passTime);
    int getpassTime();
    
    private:
    std::string name;
    int score;
    Hand* hand;
    int passTime;
    

};

#endif // ASSIGN2_PLAYER_H