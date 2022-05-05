#include "Player.h"

Player::Player(std::string playerName){
    name = playerName;
}
Player::~Player(){
    delete hand;
}

//maybe can use replaceTile() instead;
void Player::placeTile(Tile* tile, int row, int col){
    hand->delTile(tile);
}
void Player::replaceTile(Tile* tile, Tile* replacement){
    hand->delTile(tile);

}
void Player::pass(){
    passTime++;
}
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