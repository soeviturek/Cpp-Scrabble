#include "Menu.h"

Menu::Menu(){
    gameEngine = new GameEngine();
}
Menu::~Menu(){
    //todo
}
void Menu::run(){
    int input = 0;
    do{
        printMenu();
        std::cin >> input;
        if(input == NEW_GAME){
            gameEngine->newGame();
            std::cout<< "Starting a New Name" << std::endl;
            //add 2 players
            //player name should only be letters

            //play
            std::cout << "Let's Play!" << std::endl;
        }
        else if(input == LOAD_GAME){
            std::cout<< "Enter the filename from which load a game" << std::endl;
            std::cout << "> ";
            std::string fileName = "";
            std::cin >> fileName;
            gameEngine->loadGame(fileName);
            //check file exists
            //check format
            //load game
            std::cout << "Scrabble game successfully loaded" << std::endl;
            
            //file does not exist
            std::cout << "File does not exist!" << std::endl;
        }
        else if(input == CREDITS){
            //display credits
            std::cout << "Name: Yuchen Wu" << std::endl;
            std::cout << "Student ID: S3776244" << std::endl;
            std::cout << "Email: s3776244@student.rmit.edu.au" << std::endl;
        }
        else if(input == QUIT){
            std::cout << "Goodbye" << std::endl;
        }
        else{
            //invalid input
        }
    }while(input != QUIT);
    
}
void Menu::publicPrintMenu(){
    printMenu();
}

void Menu::printMenu(){
    std::cout << "Menu" << std::endl;
    std::cout << "----" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Credits (Show student information)" << std::endl;
    std::cout << "4. Quit" << std::endl;


}