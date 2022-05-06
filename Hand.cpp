#include "Hand.h"

Hand::Hand(){
    numOfTiles = 0;
    hand = new LinkedList();
}

Hand::~Hand(){
    hand->clear();
    delete hand;
}

Hand::Hand(Hand& other){
    hand = new LinkedList(*other.hand);
    numOfTiles = other.numOfTiles;
}

bool Hand::addTile(Tile* tile){
    bool check = false;
    if(hand->addBack(tile)){
        numOfTiles++;
        check = true;
    };
    return check;
}
bool Hand::delTile(Tile* tile){
    bool check = false;
    int index = hand->getIndex(tile);
    if(hand->remove(index)){
        numOfTiles--;
        check = true;
    }
    return check;
}

int Hand::getNumOfTiles(){
    return numOfTiles;
}
Tile* Hand::getTile(int index){
    return hand->get(index);
}
std::string Hand::printHand(){
    std::string handString = "Your hand is\n";
    for(int i = 0; i < hand->getSize(); ++i){
        Tile* tile = hand->get(i);
         handString += tile->letter;
         handString += "-";
         handString += std::to_string(tile->value);
         handString += " ";
    }
    return handString;
}