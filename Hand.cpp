#include "Hand.h"

Hand::Hand(){

}

Hand::~Hand(){
    hand->clear();
    delete hand;
}


bool Hand::addTile(Tile* tile){
    return hand->addBack(tile);
}
bool Hand::delTile(Tile* tile){
    return hand->addBack(tile);
}