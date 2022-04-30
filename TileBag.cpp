#include "TileBag.h"

TileBag::TileBag(){
    readTileBagFromFile();
}

void TileBag::readTileBagFromFile(){
    std::ifstream file(PATH);
    while(!file.eof() && numberOfTiles < MAX_TILE_BAG_SIZE) {
      Letter letter = 'A';
      Value value = 1;
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
   std::uniform_int_distribution<int> uniform_dist(0, MAX_HAND_SIZE);
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
   while (i < MAX_HAND_SIZE) {         // && deck->get(randIndex) != nullptr
      // Pick a random card from the deck!!!!
      Tile* tile = getRandomTile();
      if(tile != nullptr){
         hand->addTile(tile);
      }
      ++i;
   }
   
   return hand;
}