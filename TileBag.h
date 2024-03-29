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
    Tile* getRandomTile(LinkedList* temp);
    void initiateHand(Hand* hand);
    int getNumOfTiles();
    void addTile(Tile* tile);
    Tile* getTile(int index);
    std::string printTileBag();
    void readTileBagFromFile();
    void removeFront();
    private:
    LinkedList* tileBag;
    void loadGameFromFile();
    static const std::string PATH;
    
};

#endif // ASSIGN2_BAG_H