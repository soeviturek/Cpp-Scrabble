
/* Represents a player's hand
@author Yuchen Wu
*/

#ifndef ASSIGN2_HAND_H
#define ASSIGN2_HAND_H
#include "Tile.h"
#include "LinkedList.h"
#include <string>
#define MAX_HAND_SIZE 7

class Hand{
    public:
    Hand();
    ~Hand();

    bool addTile(Tile* tile);
    bool delTile(Tile* tile);
    Tile* getTile(int index);
    int getNumOfTiles();
    std::string printHand();
    private:
    LinkedList* hand;
    int numOfTiles;
};

#endif // ASSIGN2_HAND_H