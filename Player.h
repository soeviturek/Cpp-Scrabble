/* Represents a player
@author Yuchen Wu
*/

#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H
#include <string>
#include "Hand.h"

class Player{
    public:
    Player();
    ~Player();

    void setScore();
    void setName();
    std::string getName();
    int getscore;
    
    private:
    std::string name;
    int score;
    Hand* hand;
    

};

#endif // ASSIGN2_PLAYER_H