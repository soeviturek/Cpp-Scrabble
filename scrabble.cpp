
#include "LinkedList.h"
#include "GameEngine.h"
#include "Menu.h"
#include <iostream>
#include "TileBag.h"
#include <vector>

#define EXIT_SUCCESS    0

int main(void) {
   Menu* menu = new Menu();
   menu->run();
   return EXIT_SUCCESS;
}
