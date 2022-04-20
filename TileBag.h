/* Represents a tile bag
@author Yuchen Wu
*/

#ifndef ASSIGN2_BAG_H
#define ASSIGN2_BAG_H
#include <vector>
#include <string>
#define PATH "/ScrabbleTile.txt"
class TileBag{
    public:
    TileBag();
    ~TileBag();

    private:
    LinkedList* tileBag;
    // void readTileBagFromFile(std::string path);
    void readTileBagFromFile();
    
};

#endif // ASSIGN2_BAG_H