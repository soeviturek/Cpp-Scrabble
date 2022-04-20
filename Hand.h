
/* Represents a player's hand
@author Yuchen Wu
*/

#ifndef ASSIGN2_HAND_H
#define ASSIGN2_HAND_H
#include "Tile.h"
#include "LinkedList.h"

class Hand{
    public:
    Hand();
    ~Hand();

    bool addTile();
    bool delTile();
    private:
    LinkedList* hand;
};

#endif // ASSIGN2_HAND_H