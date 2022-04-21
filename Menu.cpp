#include "Menu.h"

Menu::Menu(){
    this->gameEngine = new GameEngine();
}
void Menu::run(){
    int input = 0;
    do{
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
void Menu::printMenu(){

}