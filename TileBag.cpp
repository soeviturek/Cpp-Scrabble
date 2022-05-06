#include "TileBag.h"

const std::string TileBag::PATH = "ScrabbleTiles.txt";

TileBag::TileBag(){
   tileBag = new LinkedList();
    readTileBagFromFile();
}
TileBag::~TileBag(){
   tileBag->clear();
   delete tileBag;
}
void TileBag::readTileBagFromFile(){
    std::ifstream file(PATH);
    Letter letter = 'A';
    Value value = 1;
    while(!file.eof() && numberOfTiles < MAX_TILE_BAG_SIZE) {
      file >> letter;
      file >> value;
      if (!file.eof()) {
         Tile* tile = new Tile();
         tile->letter = letter;
         tile->value = value;
         tileBag->addBack(tile);

         numberOfTiles++;
      }
   }
   file.close();
}

LinkedList* TileBag::getTileBag(){
   return tileBag;
}

Tile* TileBag::getRandomTile(){
   Tile* tile = nullptr;
   std::random_device randomSeed;
   std::uniform_int_distribution<int> uniform_dist(0, tileBag->getSize());
   int randIndex = uniform_dist(randomSeed);
   if (tileBag->get(randIndex) != nullptr) {
      tile = new Tile(*tileBag->get(randIndex));
      tileBag->remove(randIndex);
   }
   return tile;
}

Hand* TileBag::initiateHand(){
   Hand* hand = new Hand();

   // Randomise the players hand!!!!
   int i = 0;
   while (i < MAX_HAND_SIZE) {// && deck->get(randIndex) != nullptr
      // Pick a random card from the deck!!!!
      Tile* tile = getRandomTile();
      if(tile != nullptr){
         hand->addTile(tile);
      }
      ++i;
   }
   
   return hand;
}

int TileBag::getNumOfTiles(){
   return numberOfTiles;
}