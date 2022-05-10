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
    return hand->getSize();
}
Tile* Hand::getTile(int index){
    return hand->get(index);
}
bool Hand::hasTile(Tile* tile){
    return hand->contains(tile);
}
void Hand::replaceTile(Tile* tileToDel, Tile* replacementTile){
    int index = hand->getIndex(tileToDel);
    Tile* tile = hand->get(index);
    delete tile;
    tile = replacementTile;
}
void Hand::setHand(std::string handString){
    //TODO
}
std::string Hand::printHand(){
    std::string handString = "";
    for(int i = 0; i < hand->getSize(); ++i){
        Tile* tile = hand->get(i);
         handString += tile->letter;
         handString += "-";
         handString += std::to_string(tile->value);
         if(i < hand->getSize()-1){
             handString += ",";
         }
    }
    handString += "\n";
    return handString;
}