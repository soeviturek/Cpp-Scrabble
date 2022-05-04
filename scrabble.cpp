
#include "LinkedList.h"
#include "GameEngine.h"
#include "Menu.h"
#include <iostream>
#include "TileBag.h"

#define EXIT_SUCCESS    0

int main(void) {
   // LinkedList* list = new LinkedList();
   // delete list;

   // std::cout << "TODO: Implement Scrabble!" << std::endl;
   // Menu* testMenu = new Menu();
   // testMenu->run();
   // delete testMenu;
   
   //test tile bag
   TileBag* tileBag = new TileBag();

   //print out tiles in the bag
   LinkedList* test = tileBag->getTileBag();
   std::cout<<"Size of Bag: "<<test->getSize() << "\n";
   std::cout << "print tiles in the list\n";
   for(int i = 0; i < test->getSize(); i++){
      Tile* tile = test->get(i);
      std::cout << tile->letter <<"-"<<tile->value<<"\n";
   }
   
   //generate hand 
   Hand* hand = tileBag->initiateHand();
   std::cout << hand->printHand();
   Tile* tempTile = new Tile();
   tempTile->letter = 'A';
   tempTile->value = 1;
   hand->delTile(tempTile);
   std::cout << hand->printHand();
   delete tileBag;
   delete hand;
   delete tempTile;

   
   return EXIT_SUCCESS;
}
