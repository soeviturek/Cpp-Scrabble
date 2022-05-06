
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
   // TileBag* tileBag = new TileBag();

   // //print out tiles in the bag
   // LinkedList* test = tileBag->getTileBag();
   // std::cout<<"Size of Bag: "<<test->getSize() << "\n";
   // std::cout << "print tiles in the list\n";
   // for(int i = 0; i < test->getSize(); i++){
   //    Tile* tile = test->get(i);
   //    std::cout << tile->letter <<"-"<<tile->value<<"\n";
   // }
   
   // //generate hand 
   TileBag* tileBag = new TileBag();
   Hand* hand = tileBag->initiateHand();
   std::cout << hand->printHand();
   // Tile* tempTile = new Tile();
   // tempTile->letter = 'A';
   // tempTile->value = 1;
   // hand->delTile(tempTile);
   // std::cout << hand->printHand();
   delete tileBag;
   delete hand;
   // delete hand;
   // delete tempTile;

<<<<<<< HEAD
   Board* board = new Board();
   Tile* tile = new Tile();
   tile->letter = 'Q';
   tile->value = 99;
   std::cout<< "Board:\n" << board->printBoard();
   board->placeTile(tile,5,5);
   std::cout<< "Place: " << board->getSquare(5,5);
   std::cout<< "Board:\n" << board->printBoard();
   delete board;
=======
   // Board* board = new Board();
   // Tile* tile = new Tile();
   // tile->letter = 'Q';
   // tile->value = 99;
   // std::cout<< "Board:\n" << board->printBoard();
   // board->placeTile(tile,5,5);
   // std::cout<< "Place: " << board->getSquare(5,5);
   // std::cout<< "Board:\n" << board->printBoard();
   // delete board;
   // delete tile;
>>>>>>> nick

   
   return EXIT_SUCCESS;
}
