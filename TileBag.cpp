#include "TileBag.h"
const std::string TileBag::PATH = "ScrabbleTiles.txt";

TileBag::TileBag(){
   numberOfTiles = 0;
   tileBag = new LinkedList();
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
Tile* TileBag::getTile(int index){
   return tileBag->get(index);
}
Tile* TileBag::getRandomTile(LinkedList* temp){
   Tile* tile = nullptr;
   std::random_device randomSeed;
   std::uniform_int_distribution<int> uniform_dist(0, temp->getSize()-1);
   int randIndex = uniform_dist(randomSeed);
   if (temp->get(randIndex) != nullptr) {
      tile = new Tile(*temp->get(randIndex));
      temp->remove(randIndex);
   }
   return tile;
}

void TileBag::initiateHand(Hand* hand){

   // Randomise the players hand!!!!
   int i = 0;
   while (i < MAX_HAND_SIZE) {
      Tile* tile = tileBag->get(0);
      if(tile != nullptr){
         hand->addTile(tile);
         ++i;
      }
   }
}
std::string TileBag::printTileBag(){
   std::string tileBagString = "";
   for(int i = 0; i < tileBag->getSize(); ++i){
      Tile* tile = tileBag->get(i);
      tileBagString += tile->letter;
      tileBagString += "-";
      tileBagString += std::to_string(tile->value);
      if(i != tileBag->getSize()){
         tileBagString += ",";
      }
   }
   tileBagString += "\n";
   return tileBagString;
}

int TileBag::getNumOfTiles(){
   return numberOfTiles;
}