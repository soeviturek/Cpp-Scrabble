
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
   Menu* menu = new Menu();
   menu->run();
   
   return EXIT_SUCCESS;
}
