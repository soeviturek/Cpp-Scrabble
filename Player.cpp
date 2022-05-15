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
void Player::loadHand(std::string handString){
    std::string temp = "";
    for(char c : handString){
        if (c == ','){
            Tile* tile = new Tile();
            tile->letter = temp.at(0);
            tile->value = temp.at(2) - '0';
            this->getHand()->addTile(tile);
            temp = "";
        } else {
            temp.push_back(c);
        }
    }
    Tile* tile = new Tile();
    tile->letter = temp.at(0);
    tile->value = temp.at(2) - '0';
    this->getHand()->addTile(tile);
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