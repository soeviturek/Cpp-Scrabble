
#ifndef ASSIGN2_MENU_H
#define ASSIGN2_MENU_H

#include "GameEngine.h"
#include <string>
#include <iostream>
#define NEW_GAME 1
#define LOAD_GAME 2
#define CREDITS 3
#define QUIT 4

class Menu {
public:

   Menu();
   ~Menu();
   
   void run();

private:
    GameEngine* gameEngine;
    void printMenu();
};

#endif // ASSIGN2_Menu_H
