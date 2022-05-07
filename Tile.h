
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include <map>
// Define a Letter type
typedef char Letter;

// Define a Value type
typedef int Value;

class Tile {
public:
   Letter letter;
   Value  value;
   Value getValue(Letter letter);

private:
   static const std::map<Letter,Value> tileMap;
};

#endif // ASSIGN2_TILE_H
