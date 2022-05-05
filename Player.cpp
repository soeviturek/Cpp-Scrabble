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
void Player::setScore(int score);
void setName(std::string playerName) {
   name = playerName;
}

void Player::setHand(Hand* hand) {
   delete hand;
   hand = new Hand(*hand);
}

Hand* Player::getHand() {
   return hand;
}

std::string getName() {
   return playerName;
}

int Player::getScore() {
   return score;
}


void setPassTime(int passTime);
int getpassTime();