
#include "LinkedList.h"
#include "GameEngine.h"
#include "Menu.h"
#include <iostream>
#include "TileBag.h"
#include <vector>

#define EXIT_SUCCESS    0

int main(void) {
   // LinkedList* list = new LinkedList();
   // delete list;

   // std::cout << "TODO: Implement Scrabble!" << std::endl;
   Menu* menu = new Menu();
   menu->run();
   // LinkedList* ll = new LinkedList();
   // for(int i = 0; i < 10; ++i){
   //    Tile* tile = new Tile();
   //    tile->letter = 'A';
   //    tile->value = i;
   //    ll->addBack(tile);
   // }
   // Tile* tile = new Tile();
   // tile ->letter = 'A';
   // tile->value = 3;
   // ll->remove(ll->getIndex(tile));
   // for(int i = 0; i < ll->getSize(); ++i){
   //    Tile* tile = ll->get(i);
   //    std::cout << i << ": " << tile->letter << "-" << tile->value << std::endl;
   // }

   // TileBag* tileBag = new TileBag();
   // std::cout << tileBag->getNumOfTiles() << std::endl;
   // for(int i = 0; i < 98; ++i){
   //    // Tile* tile = tileBag->getTile(i);
   //    std::cout << i << ": " << tile->letter << "-" << tile->value << std::endl;
   // }
   // int count =1 ;
   // while(tileBag->getNumOfTiles() > 0){
   //    std::cout << tileBag->getNumOfTiles() << std::endl;
   //    Tile* tile = tileBag->getRandomTile();
   //    if(tile == nullptr){
   //       std::cout << "NULLPTR!!!!!!!!!!!:::::";
   //    }else {
   //       std::cout << "Go!::";
   //    }
   //    std::cout << count << ": " << tile->letter << "-" << tile->value << std::endl;
   //    count++;
   // }

   // std::vector<Player*> players;  
   // for(int i = 0; i < 5; ++i){
   //    Player* player = new Player("A"+std::to_string(i));
   //    players.push_back(player);
   // }
   // for(Player* player : players){
   //    tileBag->initiateHand(player->getHand());
   //    std::cout << player->getHand()->printHand();
   // }
   // std::cout << players[0]->getHand()->printHand();
   return EXIT_SUCCESS;
}
