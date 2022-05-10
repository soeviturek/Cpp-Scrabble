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
#define MAX_TILE_BAG_SIZE 98
class TileBag{
    public:
    TileBag();
    ~TileBag();
    LinkedList* getTileBag();
    Tile* getRandomTile();
    void initiateHand(Hand* hand);
    int getNumOfTiles();
    Tile* getTile(int index);
    std::string printTileBag();

    private:
    int numberOfTiles;
    LinkedList* tileBag;
    void readTileBagFromFile();
    void loadGameFromFile();
    static const std::string PATH;
    
};

#endif // ASSIGN2_BAG_H