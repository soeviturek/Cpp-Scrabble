#include "Player.h"

Player::Player(){
    name = "";
    hand = new Hand();
}
Player::Player(std::string playerName){
    name = playerName;
    hand = new Hand();
}
Player::~Player(){
    delete hand;
}


void Player::placeTile(Tile* tile){
    hand->delTile(tile);
}
void Player::drawTile(Tile* tile){
    hand->addTile(tile);
}
bool Player::replaceTile(Tile* tile, Tile* replacement){
    bool check = true;
    check = hand->delTile(tile);
    if(check){
        hand->addTile(replacement);
    }
    

    return check;

}
void Player::pass(){
    passTime++;
}
std::string Player::printHand(){
    std::string handString = "";
    for(int i = 0; i < hand->getNumOfTiles(); ++i){
        Tile* tile = hand->getTile(i);
        handString += tile->letter;
        handString += "-";
        handString += tile->value;
        if(i<hand->getNumOfTiles()){
            handString += ", ";
        }
    }
    return handString;
}

//player settings
void Player::setScore(int score){
    this->score = score;
}
void Player::setName(std::string playerName) {
   name = playerName;
}

void Player::setHand(Hand* hand) {
   if(hand != nullptr){
       delete hand;
   }
   hand = new Hand(*hand);
}

Hand* Player::getHand() {
   return hand;
}

std::string Player::getName() {
   return name;
}

int Player::getScore() {
   return score;
}


void Player::setPassTime(int passTime){
    this->passTime = passTime;
}
int Player::getpassTime(){
    return passTime;
}