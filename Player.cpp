#include "Player.h"

Player::Player(std::string playerName){
    name = playerName;
}
Player::~Player(){
    delete hand;
}