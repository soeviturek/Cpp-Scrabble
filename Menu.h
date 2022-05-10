
#ifndef ASSIGN2_MENU_H
#define ASSIGN2_MENU_H

#include "GameEngine.h"
#include <string>
#include <iostream>


class Menu {
public:

   Menu();
   ~Menu();
   
   void run();
private:
    GameEngine* gameEngine;
    void printMenu();
    static const std::string newGame;
    static const std::string loadGame;
    static const std::string credit;
    static const std::string quit;
};

#endif // ASSIGN2_Menu_H
