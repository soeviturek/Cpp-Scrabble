/* Represents a tile bag
@author Yuchen Wu
*/

#ifndef ASSIGN2_BAG_H
#define ASSIGN2_BAG_H
#include <string>
#include <fstream>
#include <random>
#include "Hand.h"
#include "Tile.h"
#include "LinkedList.h"
#define PATH "/ScrabbleTile.txt"
#define MAX_TILE_BAG_SIZE 98
class TileBag{
    public:
    TileBag();
    ~TileBag();
    LinkedList* getTileBag();
    Tile* getRandomTile();
    Hand* initiateHand();

    private:
    int numberOfTiles;
    LinkedList* tileBag;
    void readTileBagFromFile();
    
};

#endif // ASSIGN2_BAG_H