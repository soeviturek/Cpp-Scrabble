
#include "LinkedList.h"
#include "GameEngine.h"
#include "Menu.h"
#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {
   LinkedList* list = new LinkedList();
   delete list;

   std::cout << "TODO: Implement Scrabble!" << std::endl;
   Menu* testMenu = new Menu();
   testMenu->run();
   delete testMenu;
   return EXIT_SUCCESS;
}
